#include <iostream>
#include <vector>

// Base classes

class Stm_
{
};

class Exp_
{
};

class StmList_
{
};

class ExpList_
{
};

typedef Stm_ *Stm;
typedef Exp_ *Exp;
typedef ExpList_ *ExpList;
typedef StmList_ *StmList;

typedef enum
{
    Plus,
    Minus,
    Times,
    Divide
} Binop;

typedef enum
{
    Greater,
    GreaterEqual,
    Less,
    LessEqual,
    EqualEqual,
    NotEqual
} ConditionalOp;

typedef enum
{
    Equals,
    PlusEquals,
    MinusEquals
} AssignOp;

typedef enum
{
    Int,
    Bool,
    None
} Typee;

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

struct BoolExp : public Exp_
{
    bool value;

    BoolExp() : value(false) {} // Default constructor
    BoolExp(bool v) : value(v) {}
};

struct DeRefExp : public Exp_
{
    IdExp exp;

    DeRefExp(IdExp e) : exp(e) {}
};

struct FuncExp : public Exp_
{
    std::string id;
    ExpList args; // Rewrite this like ExpList

    FuncExp(std::string i, ExpList a) : id(i), args(a) {}
};

struct PairExpList : public ExpList_
{
    Exp head;
    ExpList tail;

    PairExpList(Exp h, ExpList t) : head(h), tail(t) {}
};

struct LastExpList : public ExpList_
{
    Exp last;

    LastExpList(Exp l) : last(l) {}
};

struct IfExp : public Exp_
{
    Exp test, then, elsee;

    IfExp(Exp t, Exp th, Exp e) : test(t), then(th), elsee(e) {}
};

struct ConditionalExp : public Exp_
{
    Exp left, right;
    ConditionalOp oper;

    ConditionalExp(Exp l, ConditionalOp o, Exp r) : left(l), oper(o), right(r) {}
};

struct NotCondExp : public Exp_
{
    Exp exp;

    NotCondExp(Exp e) : exp(e) {}
};

struct BlockExp : public Exp_
{
    StmList stms;
    Exp exp;

    BlockExp(StmList s, Exp e) : stms(s), exp(e) {}
};

struct PairStmList : public StmList_
{
    Stm head;
    StmList tail;

    PairStmList(Stm h, StmList t) : head(h), tail(t) {}
};

struct LastStmList : public StmList_
{
    Stm last;

    LastStmList(Stm l) : last(l) {}
};

struct AssignStm : public Stm_
{
    std::string id;
    AssignOp oper;
    Exp exp;

    AssignStm(std::string i, AssignOp o, Exp e) : id(i), oper(o), exp(e) {}
};

struct PointerAssignStm : public Stm_
{
    std::string id;
    AssignOp op;
    Exp expr;

    PointerAssignStm(std::string i, AssignOp o, Exp e) : id(i), op(o), expr(e) {}
};

struct ExpStm : public Stm_
{
    Exp exp;

    ExpStm(Exp e) : exp(e) {}
};

struct IfStm : public Stm_
{
    Exp test;
    Stm then, elsee;

    IfStm(Exp t, Stm th, Stm e) : test(t), then(th), elsee(e) {}
};

struct BlockStm : public Stm_
{
    StmList stms;

    BlockStm(StmList s) : stms(s) {}
};

struct WhileStm : public Stm_
{
    Exp test;
    Stm body;

    WhileStm(Exp t, Stm b) : test(t), body(b) {}
};

struct DeclaringStm : public Stm_
{
    std::string id;
    bool isMutable;
    Typee typee;

    DeclaringStm(std::string i, bool m, Typee t) : id(i), isMutable(m), typee(t) {}
};

struct LetStm : public Stm_
{
    std::string id;
    bool isMutable;
    Typee typee;
    Exp exp;

    LetStm(std::string i, bool m, Typee t, Exp e) : id(i), isMutable(m), typee(t), exp(e) {}
};

struct PrintStm : public Stm_
{
    std::string value;

    PrintStm(std::string s) : value(s) {}
};

struct FuncStm : public Stm_
{
    std::string id;
    StmList args;
    Typee returnType;
    Stm body;

    FuncStm(std::string i, StmList a, Typee r, Stm b) : id(i), args(a), returnType(r), body(b) {}
};

struct FuncExpStm : public Stm_
{
    std::string id;
    Exp args;

    FuncExpStm(std::string i, Exp a) : id(i), args(a) {}
};

struct ParamStm : public Stm_
{
    std::string id;
    bool isMutable;
    Typee type;

    ParamStm(std::string i, bool m, Typee t) : id(i), isMutable(m), type(t) {}
};

struct Program : public Stm_
{
    StmList stms;

    Program(StmList s) : stms(s) {}
};