#include <string>

#ifndef ABSYN_HPP
#define ABSYN_HPP

/* Heading (Look with CTRL+F)

1. Base classes
2. Typedefs
3. Enums
4. Expressions
    - ID expression
    - Bool expression
    - Num expression
    - Binop expression
    - If expression
    - Block expression
    - Grouped expression
    - Function expression
5. Conditionals
    - Not conditional
    - Compare conditional
    - And conditional
    - Or conditional
6. Statements
    - Let statement
    - Assign statement
    - Compound statement
    - Function statement
    - Block statement
    - Declaration statement
    - If statement
    - Print statement
    - Var print statement
    - Expr statement
    - While statement
7. Functions
    - Function definition statement
    - Function definition expression
8. Lists
    - Parameters List
    - Arguments List
    - Function List
9. Program
*/

// Base classes
class Stm_
{
public:
    virtual ~Stm_() = default;
};
class Exp_
{
public:
    virtual ~Exp_() = default;
};
class Func_
{
public:
    virtual ~Func_() = default;
};

class ExpList_
{
public:
    virtual ~ExpList_() = default;
};
class FuncList_
{
public:
    virtual ~FuncList_() = default;
};

// Typedefs
typedef Stm_ *Stm;
typedef Exp_ *Exp;
typedef Func_ *Func;
typedef ExpList_ *ExpList;
typedef FuncList_ *FuncList;

// Enums
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

enum DataType
{
    None,
    Int,
    Bool
};

// Expressions
// ID expression
struct IdExp : public Exp_
{
    std::string id;
    IdExp(std::string id) : id(id) {}
};

// Bool expression
struct BoolExp : public Exp_
{
    bool value;
    BoolExp(bool value) : value(value) {}
};

// Num expression
struct NumExp : public Exp_
{
    int num;
    NumExp(int num) : num(num) {}
};

// Binary operation expression
struct BinopExp : public Exp_
{
    Exp left, right;
    Binop op;
    BinopExp(Exp l, Binop o, Exp r) : left(l), op(o), right(r) {}
};

// If expression
struct IfExp : public Exp_
{
    Exp condition;
    Exp then;
    Exp elsee;
    IfExp(Exp c, Exp t) : condition(c), then(t) {}
    IfExp(Exp c, Exp t, Exp e) : condition(c), then(t), elsee(e) {}
};

// Block expression
struct BlockExp : public Exp_
{
    Stm stm;
    Exp exp;
    BlockExp(Stm s, Exp e) : stm(s), exp(e) {}
};

// Grouped expression
struct GroupedExp : public Exp_
{
    Exp exp;
    GroupedExp(Exp e) : exp(e) {}
};

// Function
struct FunctionExp : public Exp_
{
    std::string id;
    ExpList args;
    FunctionExp(std::string id, ExpList a) : id(id), args(a) {}
};

// Conditionals
struct ConditionalExp : public Exp_
{
    Exp condintion;
    ConditionalExp(Exp v) : condintion(v) {}
};

// Not conditional
struct NotCondExp : public Exp_
{
    Exp exp;
    NotCondExp(Exp e) : exp(e) {}
};

// Compare conditional
struct CompareCondExp : public Exp_
{
    Exp left, right;
    ConditionalOp op;
    CompareCondExp(Exp l, ConditionalOp o, Exp r) : left(l), op(o), right(r) {}
};

// And conditional
struct AndCond : public Exp_
{
    Exp left, right;
    AndCond(Exp l, Exp r) : left(l), right(r) {}
};

// Or conditional
struct OrCond : public Exp_
{
    Exp left, right;
    OrCond(Exp l, Exp r) : left(l), right(r) {}
};

// Equal conditional
struct EqualCond : public Exp_
{
    Exp left, right;
    EqualCond(Exp l, Exp r) : left(l), right(r) {}
};

// Statements
// Let statment
struct LetStm : public Stm_
{
    std::string id;
    Exp exp;
    DataType type;
    bool isMutable = false;

    LetStm(std::string id, Exp exp, bool m) : id(id), exp(exp), isMutable(m) {}
    LetStm(std::string id, Exp exp, DataType t, bool m) : id(id), exp(exp), type(t), isMutable(m) {}
};

// Assign statement
struct AssignStm : public Stm_
{
    std::string id;
    AssignOp op;
    Exp exp;
    AssignStm(std::string id, AssignOp op, Exp exp) : id(id), op(op), exp(exp) {}
};

// Compound statement
struct CompoundStm : public Stm_
{
    Stm left, right;
    CompoundStm(Stm l, Stm r) : left(l), right(r) {}
};

// Function statement
struct FunctionStm : public Stm_
{
    std::string id;
    ExpList params;
    Stm body;
    DataType returnType;
    FunctionStm(std::string id, ExpList params, Stm body) : id(id), params(params), body(body) {}
};

// Block statement
struct BlockStm : public Stm_
{
    Stm stmnt;
    BlockStm(Stm stm) : stmnt(stm) {}
};

// Declaration statement
struct DeclarationStm : public Stm_
{
    std::string id;
    DataType type;
    bool isMutable = false;
    DeclarationStm(std::string id, DataType type, bool m) : id(id), type(type), isMutable(m) {}
};

// If statement
struct IfStm : public Stm_
{
    Exp condition;
    Stm then;
    Stm elsee;
    IfStm(Exp c, Stm t) : condition(c), then(t) {}
    IfStm(Exp c, Stm t, Stm e) : condition(c), then(t), elsee(e) {}
};

// Print statement
struct VarPrintStm : public Stm_
{
    Exp exp;
    VarPrintStm(Exp e) : exp(e) {}
};

// Var print statement
struct PrintStm : public Stm_
{
    std::string id;
    PrintStm(std::string id) : id(id) {}
};

// Expr statement
struct ExprStm : public Stm_
{
    Exp exp;
    ExprStm(Exp e) : exp(e) {}
};

// While statement
struct WhileStm : public Stm_
{
    Exp condition;
    Stm body;
    WhileStm(Exp c, Stm b) : condition(c), body(b) {}
};

// Functions
// Function definition statement
struct FuncDefStm : public Func_
{
    std::string id;
    ExpList params;
    DataType returnType = None;
    Stm body;
    FuncDefStm(std::string id, ExpList p, Stm b) : id(id), params(p), body(b) {}
    FuncDefStm(std::string id, ExpList p, DataType t, Stm b) : id(id), params(p), returnType(t), body(b) {}
};

// Function definition expression
struct FuncDefExp : public Func_
{
    std::string id;
    ExpList params;
    DataType returnType = None;
    Exp body;
    FuncDefExp(std::string id, ExpList p, Exp b) : id(id), params(p), body(b) {}
    FuncDefExp(std::string id, ExpList p, DataType t, Exp b) : id(id), params(p), returnType(t), body(b) {}
};

// Lists
// Parameters List
struct PairParamExpList : public ExpList_
{
    std::string id;
    DataType type;
    ExpList tail;
    PairParamExpList(std::string id, DataType t, ExpList tail) : id(id), type(t), tail(tail) {}
};

struct LastParamExpList : public ExpList_
{
    std::string id;
    DataType type;
    LastParamExpList(std::string id, DataType t) : id(id), type(t) {}
};

// Arguments List
struct PairArgsExpList : public ExpList_
{
    Exp head;
    ExpList tail;
    PairArgsExpList(Exp h, ExpList t) : head(h), tail(t) {}
};

struct LastArgsExpList : public ExpList_
{
    Exp last;
    LastArgsExpList(Exp l) : last(l) {}
};

// Function List
struct PairFuncList : public FuncList_
{
    Func head;
    FuncList tail;
    PairFuncList(Func h, FuncList t) : head(h), tail(t) {}
};

struct LastFuncList : public FuncList_
{
    Func last;
    LastFuncList(Func l) : last(l) {}
};

// Start program
struct Program : public Stm_
{
    FuncList funcs;
    Program(FuncList f) : funcs(f) {}
};

#endif // ABSYN_HPP
