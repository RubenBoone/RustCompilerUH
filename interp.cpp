#include "absyn.hpp"
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

Value BlockExp::interp(Table *t)
{
    t->enterScope();
    if (stm != nullptr)
    {
        stm->interp(t);
    }
    Value v = exp->interp(t);
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
    Value v = exp->interp(t);
    t->setValue(id, v);
}

void AssignStm::interp(Table *t)
{
    // Use case to detemine += or -= or =
    Value v = exp->interp(t);

    switch (op)
    {
    case Equals:
        t->setValue(id, v);
        break;
    case PlusEquals:
        t->setValue(id, Value(t->getValue(id).intValue + v.intValue));
        break;
    case MinusEquals:
        t->setValue(id, Value(t->getValue(id).intValue - v.intValue));
        break;
    }
}

void DeclarationStm::interp(Table *t)
{
    t->setValue(id, Value());
}

void IfStm::interp(Table *t)
{
    if (condition->interp(t).boolValue)
    {
        then->interp(t);
    }
}

void IfElseStm::interp(Table *t)
{
    if (condition->interp(t).boolValue)
    {
        then->interp(t);
    }
    else
    {
        elsee->interp(t);
    }
}

void VarPrintStm::interp(Table *t)
{
    Value v = t->getValue(id);

    switch (v.type)
    {
    case Int:
        printf("%d\n", v.intValue);
        break;
    case Bool:
        printf("%s\n", v.boolValue ? "true" : "false");
        break;
    default:
        break;
    }
}

void PrintStm::interp(Table *t)
{
    printf("%s\n", id.c_str());
}

void ExprStm::interp(Table *t)
{
    return; // Useless, skip
}

void WhileStm::interp(Table *t)
{
    Value v = condition->interp(t);
    while (v.boolValue)
    {
        body->interp(t);
        v = condition->interp(t);
    }
}

// Expressions
Value IdExp::interp(Table *t)
{
    // Get value from table
    return t->getValue(id);
}

Value BoolExp::interp(Table *t)
{
    return Value(value);
}

Value NumExp::interp(Table *t)
{
    return Value(num);
}

Value BinopExp::interp(Table *t)
{
    Value leftResult = left->interp(t);
    Value rightResult = right->interp(t);

    int result;

    switch (op)
    {
    case Plus:
        result = leftResult.intValue + rightResult.intValue;
        break;
    case Minus:
        result = leftResult.intValue - rightResult.intValue;
        break;
    case Times:
        result = leftResult.intValue * rightResult.intValue;
        break;
    case Divide:
        if (rightResult.intValue == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        result = leftResult.intValue / rightResult.intValue;
        break;
    default:
        std::cerr << "Invalid operator" << std::endl;
        exit(1);
    }
    return Value(result);
}

Value IfElseExp::interp(Table *t)
{

    if (condition->interp(t).boolValue)
    {
        return then->interp(t);
    }
    else
    {
        return elsee->interp(t);
    }
}

Value GroupedExp::interp(Table *t)
{
    Value result = exp->interp(t);

    switch (result.type)
    {
    case Int:
        return Value(result.intValue);
    case Bool:
        return Value(result.boolValue);
    }
    std::cerr << "Invalid type" << std::endl;
    exit(1);
}

Value FunctionExp::interp(Table *t)
{
    // Call function
    return new Value();
}

Value NotCondExp::interp(Table *t)
{
    return Value(!exp->interp(t).boolValue);
}

Value CompareCondExp::interp(Table *t)
{
    Value leftResult = left->interp(t);
    Value rightResult = right->interp(t);
    bool result;

    switch (op)
    {
    case Greater:
        result = leftResult.intValue > rightResult.intValue;
        break;
    case GreaterEqual:
        result = leftResult.intValue >= rightResult.intValue;
        break;
    case Less:
        result = leftResult.intValue < rightResult.intValue;
        break;
    case LessEqual:
        result = leftResult.intValue <= rightResult.intValue;
        break;
    case EqualEqual:
        result = leftResult.intValue == rightResult.intValue;
        break;
    case NotEqual:
        result = leftResult.intValue != rightResult.intValue;
        break;
    }
    return Value(result);
}

Value AndCond::interp(Table *t)
{
    Value leftResult = left->interp(t);
    Value rightResult = right->interp(t);

    return Value(leftResult.boolValue && rightResult.boolValue);
}

Value OrCond::interp(Table *t)
{
    Value leftResult = left->interp(t);
    Value rightResult = right->interp(t);

    return Value(leftResult.boolValue || rightResult.boolValue);
}