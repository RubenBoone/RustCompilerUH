#include "absyn.hpp"

void Table::saveVariable(const std::string &id, Value *value)
{
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        if (scope->find(id) != scope->end())
        {
            (*scope)[id].value = value;
            return;
        }
    }
    std::cerr << "Variable '" << id << "' not found" << std::endl;
}

Value *Table::getVariable(const std::string &id)
{
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        if (scope->find(id) != scope->end())
        {
            return (*scope)[id].value;
        }
    }
    std::cerr << "Variable '" << id << "' not found" << std::endl;
    return nullptr;
}

void Table::print(){
    for (auto scope = variableScopes.rbegin(); scope != variableScopes.rend(); ++scope)
    {
        for (auto &var : *scope)
        {
            std::cout << var.first << " : " << var.second.value->getInt() << std::endl;
        }
    }
}

void Program::interp(Table *t)
{
    funcs->interp(t);
}

void PairFuncList::interp(Table *t)
{
    head->interp(t);
    tail->interp(t);
}

void LastFuncList::interp(Table *t)
{
    last->interp(t);
}

void FuncDefStm::interp(Table *t)
{
    t->enterScope();

    body->interp(t);

    t->exitScope();
}

void FuncDefExp::interp(Table *t)
{
    t->enterScope();

    body->interp(t);

    t->exitScope();
}

void BlockStm::interp(Table *t)
{
    t->enterScope();
    if (stmnt != nullptr)
    {
        stmnt->interp(t);
    }
    t->exitScope();
}

Value *BlockExp::interp(Table *t)
{
    t->enterScope();
    if (stm != nullptr)
    {
        stm->interp(t);
    }
    Value *v = exp->interp(t);
    t->exitScope();
    return new Value();
}

void CompoundStm::interp(Table *t)
{
    if (left != nullptr)
    {
        left->interp(t);
    }
    if (right != nullptr)
    {
        right->interp(t);
    }
}

void LetStm::interp(Table *t)
{
    Value *v = exp->interp(t);
}

void AssignStm::interp(Table *t)
{
    // Use case to detemine += or -= or =
    Value *v = exp->interp(t);
}

void DeclarationStm::interp(Table *t)
{
    // Add variable to table with null
}

void IfStm::interp(Table *t)
{
    condition->interp(t);
    then->interp(t);
}

void IfElseStm::interp(Table *t)
{
    condition->interp(t);
    then->interp(t);
    elsee->interp(t);
}

void VarPrintStm::interp(Table *t)
{
    DataType type = t->lookupVariable(id);
}

void PrintStm::interp(Table *t)
{
    printf("%s\n", id.c_str());
}

void ExprStm::interp(Table *t)
{
    // Can skip this because this does nothing
    return;
}

void WhileStm::interp(Table *t)
{
    Value *v = condition->interp(t);
    body->interp(t);
}

// Expressions
Value *IdExp::interp(Table *t)
{
    // Get value from table

    return new Value();
}

Value *BoolExp::interp(Table *t)
{
    return new BoolValue(value);
}

Value *NumExp::interp(Table *t)
{
    return new IntValue(num);
}

Value *BinopExp::interp(Table *t)
{
    Value *leftResult = left->interp(t);
    Value *rightResult = right->interp(t);

    int result;

    // switch (op)
    // {
    // case Plus:
    //     result = leftResult->getInt() + rightResult->getInt();
    //     break;
    // case Minus:
    //     result = leftResult->getInt() - rightResult->getInt();
    //     break;
    // case Times:
    //     result = leftResult->getInt() * rightResult->getInt();
    //     break;
    // case Divide:
    //     if (rightResult->getInt() == 0)
    //     {
    //         throw std::runtime_error("Division by zero");
    //     }
    //     result = leftResult->getInt() / rightResult->getInt();
    //     break;
    // default:
    //     std::cerr << "Invalid operator" << std::endl;
    //     exit(1);
    // }
    return new Value();
}

Value *IfElseExp::interp(Table *t)
{
    // Return value
    condition->interp(t);
    then->interp(t);
    elsee->interp(t);
    return new Value();
}

Value *GroupedExp::interp(Table *t)
{
    // Don't forget this has priority
    exp->interp(t);
    return new Value();
}

Value *FunctionExp::interp(Table *t)
{
    // Call function
    return new Value();
}

Value *NotCondExp::interp(Table *t)
{
    exp->interp(t);
    return new Value();
}

Value *CompareCondExp::interp(Table *t)
{
    switch (op)
    {
    case Greater:
        break;
    case GreaterEqual:
        break;
    case Less:
        break;
    case LessEqual:
        break;
    case EqualEqual:
        break;
    case NotEqual:
        break;
    }
    return new Value();
}

Value *AndCond::interp(Table *t)
{
    left->interp(t);
    right->interp(t);
    return new Value();
}

Value *OrCond::interp(Table *t)
{
    left->interp(t);
    right->interp(t);
    return new Value();
}