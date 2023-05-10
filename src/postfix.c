#include "../include/postfix.h"
struct PostfixElementArray* createPostfixElementArray()
{
    struct PostfixElementArray* ret = (struct PostfixElementArray*)malloc(sizeof(struct PostfixElementArray));
    memset(ret->array, 0, sizeof(struct PostfixElement));
    ret->num = 0;
    return ret;
}

int pushToPostfixArray(struct PostfixElementArray* array, struct PostfixElement obj)
{
    array->array[array->num] = obj;
    array->num++;
    return array->num;
}

struct PostfixElement generateSymbolElement(char symbol)
{
    struct PostfixElement ret;
    ret.elementStatus = 1;
    ret.symbol = symbol;
    return ret;
}

struct PostfixElement generateNumberElement(double num)
{
    struct PostfixElement ret;
    ret.elementStatus = 0;
    ret.number = num;
    return ret;
}

void deletePostfixElementArray(struct PostfixElementArray* obj)
{
    free(obj);
    obj = NULL;
}