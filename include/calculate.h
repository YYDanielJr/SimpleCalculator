#pragma once
#include "stack.h"
#include "postfix.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
struct result
{
    double resultNumber;
    int resultStatusNumber;
};

// 创建后缀表达式
void departToPostfix(struct PostfixElementArray*, char*);
double calculate(char*);