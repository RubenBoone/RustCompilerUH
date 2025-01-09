#include "absyn.hpp"
#include <iostream>

DataType Table::lookupVariable(const std::string &id)
{
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        if (scope->find(id) != scope->end())
        {
            return (*scope)[id].type;
        }
    }
    return Error;
}

DataType Table::lookupFunction(const std::string &id)
{
    if (functions.find(id) != functions.end())
    {
        return functions[id].returnType;
    }
    return Error;
}

DataType Table::lookupFunctionParam(const std::string &fid, int index)
{
    if (functions.find(fid) != functions.end())
    {
        if (functions[fid].params.find(index) != functions[fid].params.end())
        {
            return functions[fid].params[index].type;
        }
    }
    std::cerr << "Too many arguments for function '" << fid << "'" << std::endl;
    typeCheckCorrect = false;
    return Error;
}

bool Table::isVarMutable(const std::string &id)
{
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        if (scope->find(id) != scope->end())
        {
            return (*scope)[id].isMutable;
        }
    }
    return false;
}

bool Table::isAssigned(const std::string &id)
{
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        if (scope->find(id) != scope->end())
        {
            return (*scope)[id].isAssigned;
        }
    }
    return false;
}

void Table::enterScope()
{
    variableScopes.push_back({});
}

void Table::exitScope()
{
    if (!variableScopes.empty())
    {
        variableScopes.pop_back();
    }
    else
    {
        std::cerr << "No scope to exit!" << std::endl;
    }
}

void Table::addVariable(const std::string &id, DataType type, bool isMutable, bool isAssigned)
{
    if (!variableScopes.empty())
    {
        variableScopes.back()[id] = {id, type, Value(), isMutable, isAssigned};
    }
}

void Table::addFunction(const std::string &id, DataType type)
{
    functions[id] = {id, type, {}};
}

void Table::addFunctionParam(const std::string &fid, const std::string &pid, Value value, int index, bool isMutable)
{
    functions[fid].params[index] = {pid, value.type, Value(), isMutable, true};
}

void Table::addParamsToScope(const std::string &fid)
{
    for (auto &param : functions[fid].params)
    {
        variableScopes.back()[param.second.id] = {param.second.id, param.second.type, Value(), param.second.isMutable, true};
    }
}

DataType IdExp::check(Table *t)
{
    DataType type = t->lookupVariable(id);
    if (type == None)
    {
        std::cerr << "ID '" << id << "' has no type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }
    return type;
}

DataType BoolExp::check(Table *t)
{
    return Bool;
}

DataType NumExp::check(Table *t)
{
    return Int;
}

DataType BinopExp::check(Table *t)
{
    DataType leftType = left->check(t);
    DataType rightType = right->check(t);

    if (leftType != Int || rightType != Int)
    {
        std::cerr << "Operands must be of type: integer" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return Int;
}

DataType IfElseExp::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    DataType thenType = then->check(t);
    DataType elseType = elsee->check(t);

    if (thenType != elseType)
    {
        std::cerr << "If and else branches must have the same type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return elseType;
}

DataType BlockExp::check(Table *t)
{
    t->enterScope();
    if (stm != nullptr)
    {
        stm->check(t);
    }
    if (exp != nullptr)
    {
        DataType expType = exp->check(t);
        t->exitScope();
        return expType;
    }
    std::cerr << "Block expression must have a return value" << std::endl;
    t->typeCheckCorrect = false;
    return Error;
}

DataType GroupedExp::check(Table *t)
{
    return exp->check(t);
}

DataType FunctionExp::check(Table *t)
{
    if (args != nullptr)
    {
        args->check(t, id, 0);
    }

    DataType functionType = t->lookupFunction(id);
    return functionType;
}

DataType NotCondExp::check(Table *t)
{
    DataType expType = exp->check(t);
    if (expType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return Bool;
}

DataType CompareCondExp::check(Table *t)
{
    DataType leftType = left->check(t);
    DataType rightType = right->check(t);

    if (leftType != rightType)
    {
        std::cerr << "Operands must be of the same type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return Bool;
}

DataType AndCond::check(Table *t)
{
    DataType leftType = left->check(t);
    DataType rightType = right->check(t);

    if (leftType != rightType)
    {
        std::cerr << "And operands must be of type bool" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return Bool;
}

DataType OrCond::check(Table *t)
{
    DataType leftType = left->check(t);
    DataType rightType = right->check(t);

    if (leftType != rightType)
    {
        std::cerr << "Or operands must be of type bool" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return Bool;
}

DataType LetStm::check(Table *t)
{
    DataType expType = exp->check(t);

    if (type == None)
    {
        type = expType;
    }

    t->addVariable(id, type, isMutable, true);
    return type;
}

DataType AssignStm::check(Table *t)
{
    DataType varType = t->lookupVariable(id);
    DataType expType = exp->check(t);

    if (!t->isVarMutable(id))
    {
        if (t->isAssigned(id))
        {
            std::cerr << "Variable '" << id << "' is not mutable" << std::endl;
            t->typeCheckCorrect = false;
            return Error;
        }
    }

    if (varType == Error)
    {
        std::cerr << "Variable '" << id << "' has not been defined" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    if (varType != expType)
    {
        std::cerr << "ASSIGN: Variable and expression must have the same type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    t->addVariable(id, expType, t->isVarMutable(id), true);
    return None;
}

DataType CompoundStm::check(Table *t)
{
    if (left != nullptr)
    {
        DataType leftType = left->check(t);
    }
    if (right != nullptr)
    {
        DataType rightType = right->check(t);
        return rightType;
    }
    return None;
}

DataType BlockStm::check(Table *t)
{
    t->enterScope();

    if (stmnt != nullptr)
    {
        DataType stmntType = stmnt->check(t);
        t->exitScope();
        return stmntType;
    }

    t->exitScope();
    return None;
}

DataType DeclarationStm::check(Table *t)
{
    t->addVariable(id, type, isMutable, false);

    return type;
}

DataType IfStm::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return then->check(t);
}

DataType IfElseStm::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    DataType thenType = then->check(t);
    DataType elseType = elsee->check(t);

    if (thenType != elseType)
    {
        std::cerr << "If and else branches must have the same type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return thenType;
}

DataType VarPrintStm::check(Table *t)
{
    if (!t->isAssigned(id))
    {
        std::cerr << "Variable '" << id << "' is not assigned" << std::endl;
        t->typeCheckCorrect = false;
    }

    return t->lookupVariable(id);
}

DataType PrintStm::check(Table *t)
{
    return None;
}

DataType ExprStm::check(Table *t)
{
    return exp->check(t);
}

DataType WhileStm::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return body->check(t);
}

DataType FuncDefStm::check(Table *t)
{
    t->enterScope();

    if (params != nullptr)
    {
        params->check(t, id, 0);
        t->addParamsToScope(id);
    }
    body->check(t);

    t->exitScope();
    return returnType;
}

DataType FuncDefExp::check(Table *t)
{
    t->enterScope();

    if (params != nullptr)
    {
        params->check(t, id, 0);
        t->addParamsToScope(id);
    }

    DataType blockType = body->check(t);
    if (blockType != returnType)
    {
        std::cerr << "Return expression does not match function type" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    t->exitScope();
    return returnType;
}

DataType PairParamExpList::check(Table *t, std::string &fid, int index)
{
    t->addFunctionParam(fid, id, type, index, isMutable);

    if (tail != nullptr)
    {
        return tail->check(t, fid, index + 1);
    }

    return None;
}

DataType LastParamExpList::check(Table *t, std::string &fid, int index)
{
    t->addFunctionParam(fid, id, type, index, isMutable);
    return None;
}

DataType PairArgsExpList::check(Table *t, std::string &fid, int index)
{
    DataType argType = head->check(t);
    DataType paramType = t->lookupFunctionParam(fid, index);
    DataType finalType = None;

    if (argType != paramType)
    {
        std::cerr << fid << "(): Types of argument at index: " << index << " does not match" << std::endl;
        t->typeCheckCorrect = false;
        finalType = Error;
    }

    if (tail != nullptr)
    {
        finalType != Error ? tail->check(t, fid, index + 1) : Error;
    }

    return finalType;
}

DataType LastArgsExpList::check(Table *t, std::string &fid, int index)
{
    DataType argType = last->check(t);
    DataType paramType = t->lookupFunctionParam(fid, index);

    if (argType != paramType)
    {
        std::cerr << fid << "(): Types of argument at index: " << index << " does not match" << std::endl;
        t->typeCheckCorrect = false;
        return Error;
    }

    return None;
}

DataType PairFuncList::check(Table *t)
{
    if (head == nullptr)
    {
        std::cout << "Head is null" << std::endl;
    }
    if (tail == nullptr)
    {
        std::cout << "Tail is null" << std::endl;
    }

    head->check(t);
    return tail->check(t);
}

DataType LastFuncList::check(Table *t)
{
    return last->check(t);
}

DataType Program::check(Table *t)
{
    funcs->declare(t);
    return funcs->check(t);
}

void FuncDefStm::declare(Table *t)
{
    if (params != nullptr)
    {
        params->check(t, id, 0);
    }

    t->addFunction(id, returnType);
}

void FuncDefExp::declare(Table *t)
{
    t->addFunction(id, returnType);
    if (params != nullptr)
    {
        params->check(t, id, 0);
    }
}

void PairFuncList::declare(Table *t)
{
    head->declare(t);
    tail->declare(t);
}

void LastFuncList::declare(Table *t)
{
    last->declare(t);
}