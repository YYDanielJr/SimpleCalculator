#include "../include/stack.h"
#include <stdlib.h>
#include <string.h>
struct DoubleStack* createDoubleStack()
{
    struct DoubleStack* ret = (struct DoubleStack*)malloc(sizeof(struct DoubleStack));
    memset(ret->array, 0, 4096);
    ret->top = 0;
    return ret;
}

struct CharStack* createCharStack()
{
    struct CharStack* ret = (struct CharStack*)malloc(sizeof(struct CharStack));
    memset(ret->array, 0, 1024);
    ret->top = 0;
    return ret;
}

int deleteDoubleStack(struct DoubleStack* obj)
{
    free(obj);
    obj = NULL;
    return 0;
}

int deleteCharStack(struct CharStack* obj)
{
    free(obj);
    obj = NULL;
    return 0;
}

int pushDouble(struct DoubleStack* obj, double element)
{
    obj->array[obj->top] = element;
    obj->top++;
    return obj->top;
}

int pushChar(struct CharStack* obj, char element)
{
    obj->array[obj->top] = element;
    obj->top++;
    return obj->top;
}

double topDouble(struct DoubleStack* obj)
{
    double ret = obj->array[obj->top - 1];
    obj->array[obj->top - 1] = 0;
    obj->top--;
    return ret;
}

char topChar(struct CharStack* obj)
{
    double ret = obj->array[obj->top - 1];
    obj->array[obj->top - 1] = 0;
    obj->top--;
    return ret;
}

double getDouble(struct DoubleStack* obj)
{
    return obj->array[obj->top - 1];
}

char getChar(struct CharStack* obj)
{
    return obj->array[obj->top - 1];
}