#include <iostream>

// Base classes

class Stm_
{
};

class Exp_
{
};

typedef Stm_ *Stm;
typedef Exp_ *Exp;

typedef enum
{
    Plus,
    Minus,
    Times,
    Div
} Binop;

// Custum classes

struct OpExp : public Exp_
{
    Exp left, right;
    Binop oper;

    OpExp(Exp l, Binop o, Exp r) : left(l), oper(o), right(r) {}
};

struct IdExp : public Exp_
{
    std::string id;

    IdExp(std::string i) : id(i) {}
};

struct NumExp : public Exp_
{
    int num;

    NumExp(int n) : num(n) {}
};