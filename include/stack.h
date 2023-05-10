#pragma once
struct DoubleStack
{
    double array[1024];
    int top;
};

struct CharStack
{
    char array[1024];
    int top;
};

// createStack系列函数用于创建栈，返回栈的指针
struct DoubleStack* createDoubleStack();
// createStack系列函数用于创建栈，返回栈的指针
struct CharStack* createCharStack();
// deleteStack函数用于删除栈
int deleteDoubleStack(struct DoubleStack*);
// deleteStack函数用于删除栈
int deleteCharStack(struct CharStack*);
// push函数用于向栈中添加数据
int pushDouble(struct DoubleStack*, double);
// push函数用于向栈中添加数据
int pushChar(struct CharStack*, char);
// top函数用于从栈中弹出数据
double topDouble(struct DoubleStack*);
// top函数用于从栈中弹出数据
char topChar(struct CharStack*);
// get函数用于得到栈顶元素
double getDouble(struct DoubleStack*);
// get函数用于得到栈顶元素
char getChar(struct CharStack*);