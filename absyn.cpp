#include "absyn.hpp"
#include <iostream>

DataType Table::lookupVariable(const std::string &id)
{
    if (variables.find(id) != variables.end())
    {
        return variables[id].type;
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
    std::cerr << "To many arguments for function '" << fid << "'" << std::endl;
    return Error;
}

void Table::addVariable(const std::string &id, DataType type)
{
    // std::cout << "Adding variable '" << id << "' with type " << type << std::endl;
    variables[id] = {id, type, false};
}

void Table::addFunction(const std::string &id, DataType type)
{
    // std::cout << "Adding function '" << id << "' with type " << type << std::endl;
    functions[id] = {id, type, {}};
}

void Table::addFunctionParam(const std::string &fid, const std::string &pid, DataType type, int index)
{
    // std::cout << "Adding parameter '" << pid << "' to function '" << fid << "' with type " << type << " and index " << index << std::endl;
    functions[fid].params[index] = {pid, type, false};
}

DataType IdExp::check(Table *t)
{
    DataType type = t->lookupVariable(id);
    if (type == None)
    {
        std::cerr << "ID '" << id << "' has no type" << std::endl;
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
        std::cerr << "Operands must be of type integer" << std::endl;
        return Error;
    }

    return Int;
}

DataType IfExp::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        return Error;
    }

    DataType thenType = then->check(t);

    return thenType;
}

DataType IfElseExp::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
        return Error;
    }

    DataType thenType = then->check(t);
    DataType elseType = elsee->check(t);

    if (thenType != elseType)
    {
        std::cerr << "If and else branches must have the same type" << std::endl;
        return Error;
    }

    return elseType;
}

DataType BlockExp::check(Table *t)
{
    if (stm != nullptr)
    {
        stm->check(t);
    }
    if (exp != nullptr)
    {
        return exp->check(t);
    }
    std::cerr << "Block expression must have a return value" << std::endl;
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
        return Error;
    }

    return Bool;
}

DataType EqualCond::check(Table *t)
{
    DataType leftType = left->check(t);
    DataType rightType = right->check(t);

    if (leftType != rightType)
    {
        std::cerr << "ERROR: Operands must be of the same type" << std::endl;
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

    t->addVariable(id, type);
    return type;
}

DataType AssignStm::check(Table *t)
{
    DataType varType = t->lookupVariable(id);

    if (varType == Error)
    {
        std::cerr << "ASSIGN: Variable '" << id << "' has no type" << std::endl;
        return Error;
    }
    DataType expType = exp->check(t);

    if (varType != expType)
    {
        std::cerr << "ASSIGN: Variable and expression must have the same type" << std::endl;
        return Error;
    }

    t->addVariable(id, expType);
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
    if (stmnt != nullptr)
    {
        return stmnt->check(t);
    }
    return None;
}

DataType DeclarationStm::check(Table *t)
{
    t->addVariable(id, type);

    return type;
}

DataType IfStm::check(Table *t)
{
    DataType condType = condition->check(t);
    if (condType != Bool)
    {
        std::cerr << "Condition must be a boolean" << std::endl;
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
        return Error;
    }

    DataType thenType = then->check(t);
    DataType elseType = elsee->check(t);

    if (thenType != elseType)
    {
        std::cerr << "If and else branches must have the same type" << std::endl;
        return Error;
    }

    return thenType;
}

DataType VarPrintStm::check(Table *t)
{
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
        return Error;
    }

    return body->check(t);
}

DataType FuncDefStm::check(Table *t)
{
    if (params != nullptr)
    {
        params->check(t, id, 0);
    }
    body->check(t);

    return returnType;
}

DataType FuncDefExp::check(Table *t)
{
    DataType blockType = body->check(t);

    if (blockType != returnType)
    {
        std::cerr << "Return expression does not match function type" << std::endl;
        return Error;
    }

    return returnType;
}

DataType PairParamExpList::check(Table *t, std::string &fid, int index)
{
    t->addFunctionParam(fid, id, type, index);

    if (tail != nullptr)
    {
        return tail->check(t, fid, index + 1);
    }

    return None;
}

DataType LastParamExpList::check(Table *t, std::string &fid, int index)
{
    t->addFunctionParam(fid, id, type, index);
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
    std::cout << "----- Declaring functions done -----" << std::endl;
    return funcs->check(t);
}

void FuncDefStm::declare(Table *t)
{
    std::cout << "Declaring function '" << id << "'" << std::endl;

    if (params != nullptr)
    {
        params->check(t, id, 0);
    }

    t->addFunction(id, returnType);
}

void FuncDefExp::declare(Table *t)
{
    std::cout << "Declaring function '" << id << "' with type " << returnType << std::endl;
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