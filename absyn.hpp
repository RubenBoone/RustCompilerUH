#include <string>
#include <unordered_map>

#ifndef ABSYN_HPP
#define ABSYN_HPP

/* Table of content (Look with CTRL+F):

1. Base classes
    - Table
    - Stm_
    - Exp_
    - Func_
    - ExpList_
    - FuncList_
2. Typedefs
    - Stm
    - Exp
    - Func
    - ExpList
    - FuncList
3. Enums
    - Binop
    - ConditionalOp
    - AssignOp
    - DataType
4. Expressions
    - ID expression
    - Bool expression
    - Num expression
    - Binop expression
    - If expression
    - If else expression
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
    - If else statement
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
    Error,
    None,
    Undefined,
    Int,
    Bool
};

// Base classes
struct VarInfo
{
    std::string id;
    DataType type;
    bool isMutable;
};

struct FuncInfo
{
    std::string id;
    DataType returnType;
    std::unordered_map<int, VarInfo> params;
};

struct Table
{
    std::unordered_map<std::string, VarInfo> variables;
    std::unordered_map<std::string, FuncInfo> functions;

    DataType lookupVariable(const std::string &id);
    DataType lookupFunction(const std::string &id);
    DataType lookupFunctionParam(const std::string &fid, int index);

    void addVariable(const std::string &id, DataType type);
    void addFunction(const std::string &id, DataType type);
    void addFunctionParam(const std::string &fid, const std::string &pid, DataType type, int index);
};
struct Stm_
{
    virtual DataType check(Table *t) = 0;
};
struct Exp_
{
    virtual DataType check(Table *t) = 0;
};
struct Func_
{
    virtual DataType check(Table *t) = 0;
    virtual void declare(Table *t) = 0;
};

struct ExpList_
{
    virtual DataType check(Table *t, std::string &fid, int index) = 0;
};
struct FuncList_
{
    virtual DataType check(Table *t) = 0;
    virtual void declare(Table *t) = 0;
};

// Typedefs
typedef Stm_ *Stm;
typedef Exp_ *Exp;
typedef Func_ *Func;
typedef ExpList_ *ExpList;
typedef FuncList_ *FuncList;

// Expressions
// ID expression
struct IdExp : public Exp_
{
    std::string id;
    IdExp(std::string id) : id(id) {}
    DataType check(Table *t);
};

// Bool expression
struct BoolExp : public Exp_
{
    bool value;
    BoolExp(bool value) : value(value) {}
    DataType check(Table *t);
};

// Num expression
struct NumExp : public Exp_
{
    int num;
    NumExp(int num) : num(num) {}
    DataType check(Table *t);
};

// Binary operation expression
struct BinopExp : public Exp_
{
    Exp left, right;
    Binop op;
    BinopExp(Exp l, Binop o, Exp r) : left(l), op(o), right(r) {}
    DataType check(Table *t);
};

// If expression
struct IfExp : public Exp_
{
    Exp condition;
    Exp then;
    IfExp(Exp c, Exp t) : condition(c), then(t) {}
    DataType check(Table *t);
};

// If else expression
struct IfElseExp : public Exp_
{
    Exp condition;
    Exp then;
    Exp elsee;
    IfElseExp(Exp c, Exp t, Exp e) : condition(c), then(t), elsee(e) {}
    DataType check(Table *t);
};

// Block expression
struct BlockExp : public Exp_
{
    Stm stm;
    Exp exp;
    BlockExp(Stm s, Exp e) : stm(s), exp(e) {}
    DataType check(Table *t);
};

// Grouped expression
struct GroupedExp : public Exp_
{
    Exp exp;
    GroupedExp(Exp e) : exp(e) {}
    DataType check(Table *t);
};

// Function expression
struct FunctionExp : public Exp_
{
    std::string id;
    ExpList args;
    FunctionExp(std::string id, ExpList a) : id(id), args(a) {}
    DataType check(Table *t);
};

// Conditionals
// Not conditional
struct NotCondExp : public Exp_
{
    Exp exp;
    NotCondExp(Exp e) : exp(e) {}
    DataType check(Table *t);
};

// Compare conditional
struct CompareCondExp : public Exp_
{
    Exp left, right;
    ConditionalOp op;
    CompareCondExp(Exp l, ConditionalOp o, Exp r) : left(l), op(o), right(r) {}
    DataType check(Table *t);
};

// And conditional
struct AndCond : public Exp_
{
    Exp left, right;
    AndCond(Exp l, Exp r) : left(l), right(r) {}
    DataType check(Table *t);
};

// Or conditional
struct OrCond : public Exp_
{
    Exp left, right;
    OrCond(Exp l, Exp r) : left(l), right(r) {}
    DataType check(Table *t);
};

// Equal conditional
struct EqualCond : public Exp_
{
    Exp left, right;
    EqualCond(Exp l, Exp r) : left(l), right(r) {}
    DataType check(Table *t);
};

// Statements
// Let statment
struct LetStm : public Stm_
{
    std::string id;
    Exp exp;
    DataType type = None;
    bool isMutable = false;

    LetStm(std::string id, Exp exp, bool m) : id(id), exp(exp), isMutable(m) {}
    LetStm(std::string id, Exp exp, DataType t, bool m) : id(id), exp(exp), type(t), isMutable(m) {}
    DataType check(Table *t);
};

// Assign statement
struct AssignStm : public Stm_
{
    std::string id;
    AssignOp op;
    Exp exp;
    AssignStm(std::string id, AssignOp op, Exp exp) : id(id), op(op), exp(exp) {}
    DataType check(Table *t);
};

// Compound statement
struct CompoundStm : public Stm_
{
    Stm left, right;
    CompoundStm(Stm l, Stm r) : left(l), right(r) {}
    DataType check(Table *t);
};

// Block statement
struct BlockStm : public Stm_
{
    Stm stmnt;
    BlockStm(Stm stm) : stmnt(stm) {}
    DataType check(Table *t);
};

// Declaration statement
struct DeclarationStm : public Stm_
{
    std::string id;
    DataType type;
    bool isMutable = false;
    bool assigned = false;
    DeclarationStm(std::string id, DataType type, bool m) : id(id), type(type), isMutable(m) {}
    DataType check(Table *t);
};

// If statement
struct IfStm : public Stm_
{
    Exp condition;
    Stm then;
    IfStm(Exp c, Stm t) : condition(c), then(t) {}
    DataType check(Table *t);
};

// If else statement
struct IfElseStm : public Stm_
{
    Exp condition;
    Stm then;
    Stm elsee;
    IfElseStm(Exp c, Stm t, Stm e) : condition(c), then(t), elsee(e) {}
    DataType check(Table *t);
};

// Print statement
struct VarPrintStm : public Stm_
{
    std::string id;
    VarPrintStm(std::string i) : id(i) {}
    DataType check(Table *t);
};

// Var print statement
struct PrintStm : public Stm_
{
    std::string id;
    PrintStm(std::string id) : id(id) {}
    DataType check(Table *t);
};

// Expr statement
struct ExprStm : public Stm_
{
    Exp exp;
    ExprStm(Exp e) : exp(e) {}
    DataType check(Table *t);
};

// While statement
struct WhileStm : public Stm_
{
    Exp condition;
    Stm body;
    WhileStm(Exp c, Stm b) : condition(c), body(b) {}
    DataType check(Table *t);
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
    DataType check(Table *t);
    void declare(Table *t);
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
    DataType check(Table *t);
    void declare(Table *t);
};

// Lists
// Parameters List
struct PairParamExpList : public ExpList_
{
    std::string id;
    DataType type;
    bool isMutable = false;
    ExpList tail;
    PairParamExpList(std::string id, DataType t, ExpList tail, bool m) : id(id), type(t), tail(tail), isMutable(m) {}
    DataType check(Table *t, std::string &fid, int index);
};

struct LastParamExpList : public ExpList_
{
    std::string id;
    DataType type;
    bool isMutable = false;
    LastParamExpList(std::string id, DataType t, bool m) : id(id), type(t), isMutable(m) {}
    DataType check(Table *t, std::string &fid, int index);
};

// Arguments List
struct PairArgsExpList : public ExpList_
{
    Exp head;
    ExpList tail;
    PairArgsExpList(Exp h, ExpList t) : head(h), tail(t) {}
    DataType check(Table *t, std::string &fid, int index);
};

struct LastArgsExpList : public ExpList_
{
    Exp last;
    LastArgsExpList(Exp l) : last(l) {}
    DataType check(Table *t, std::string &fid, int index);
};

// Function List
struct PairFuncList : public FuncList_
{
    Func head;
    FuncList tail;
    PairFuncList(Func h, FuncList t) : head(h), tail(t) {}
    DataType check(Table *t);
    void declare(Table *t);
};

struct LastFuncList : public FuncList_
{
    Func last;
    LastFuncList(Func l) : last(l) {}
    DataType check(Table *t);
    void declare(Table *t);
};

// Start program
struct Program : public Stm_
{
    FuncList funcs;
    Program(FuncList f) : funcs(f) {}
    DataType check(Table *t);
};

#endif // ABSYN_HPP
