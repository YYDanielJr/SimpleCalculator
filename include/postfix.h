#pragma once
#include <stdlib.h>
#include <string.h>
struct PostfixElement
{
    // 0为数字，1为运算符
    int elementStatus;
    // 如果是数字，表示数字大小，否则无意义
    double number;
    // 如果是运算符，表示符号内容，否则无意义
    // 依次是s，c，t，*，/，+，-
    char symbol;
};

struct PostfixElementArray
{
    struct PostfixElement array[1024];
    int num;
};

struct PostfixElementArray* createPostfixElementArray();
int pushToPostfixArray(struct PostfixElementArray*, struct PostfixElement);
struct PostfixElement generateSymbolElement(char);
struct PostfixElement generateNumberElement(double);
void deletePostfixElementArray(struct PostfixElementArray*);