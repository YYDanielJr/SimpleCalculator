#include "../include/calculate.h"
/**
 * priorityMap是一张算术符号优先级的映射表。
 * 在其中，sin、cos和tan的优先级最高，为1。
 * *和/的优先级其次，为2。
 * +和-的优先级最低，为3。
 * 所以数组代表的的内容依次是s，c，t，*，/，+，-。
 */
int priorityMap['u'];

void departToPostfix(struct PostfixElementArray* result, char* buffer)
{
    priorityMap['s'] = 1;
    priorityMap['c'] = 1;
    priorityMap['t'] = 1;
    priorityMap['*'] = 2;
    priorityMap['/'] = 2;
    priorityMap['+'] = 3;
    priorityMap['-'] = 3;
    priorityMap['('] = 4;
    priorityMap[')'] = 4;
    struct CharStack* char_stack = createCharStack();
    int fast = 0;
    int slow = 0;
    while(buffer[slow] != 0)
    {
        if(buffer[fast] >= '0' && buffer[fast] <= '9' || buffer[fast] == '.' || (fast == slow && buffer[fast] == '-'))
        {
            fast++;
        }
        else
        {
            // 从字符串中分离数字
            if(buffer[slow] >= '0' && buffer[slow] <= '9')
            {
                char temp[32] = {0};
                for(int i = slow, j = 0; i < fast; i++, j++)
                {
                    temp[j] = buffer[i];
                }
                pushToPostfixArray(result, generateNumberElement(atof(temp)));
            }
            // 如果快指针是特殊字符，先看是不是pi
            if(buffer[fast] == 'p')
            {
                pushToPostfixArray(result, generateNumberElement(acos(-1)));
            }
            // 此时快指针一定指在运算符或结尾上，读取运算符入栈
            else if((char_stack->top == 0 || priorityMap[getChar(char_stack)] > priorityMap[buffer[fast]] || buffer[fast] == '(') && buffer[fast] != 0)
            {
                // 符合入栈规则的入栈
                pushChar(char_stack, buffer[fast]);
            }
            else    // 否则做右括号或者其他运算符对应的处理
            {
                if(buffer[fast] == ')')
                {
                    while(getChar(char_stack) != '(')
                    {
                        pushToPostfixArray(result, generateSymbolElement(topChar(char_stack)));
                    }
                    topChar(char_stack);    // 清理左括号
                }
                else if(buffer[fast] != 0)  // 优先级问题，清理优先级更高的出栈
                {
                    while(priorityMap[getChar(char_stack)] <= priorityMap[buffer[fast]] && char_stack->top > 0)
                    {
                        pushToPostfixArray(result, generateSymbolElement(topChar(char_stack)));
                    }
                    pushChar(char_stack, buffer[fast]);
                }
                else    // 快指针指向结尾，清空栈
                {
                    while(char_stack->top > 0)
                    {
                        pushToPostfixArray(result, generateSymbolElement(topChar(char_stack)));
                    }
                }
            }
            fast++;
            slow = fast;
        }
    }
    while(char_stack->top > 0)  // 如果最后是运算符，会导致运算符残留，再清理
    {
        pushToPostfixArray(result, generateSymbolElement(topChar(char_stack)));
    }
    deleteCharStack(char_stack);
}

double calculate(char* buffer)
{
    double ret;
    double temp = 0.0;
    struct PostfixElementArray* array = createPostfixElementArray();
    struct DoubleStack* stack = createDoubleStack();
    departToPostfix(array, buffer);

    for(int i = 0; i < array->num; i++)
    {
        if(array->array[i].elementStatus == 0)
        {
            pushDouble(stack, array->array[i].number);
        }
        else
        {
            if(array->array[i].symbol == 's')
            {
                pushDouble(stack, sin(topDouble(stack)));
            }
            else if(array->array[i].symbol == 'c')
            {
                pushDouble(stack, cos(topDouble(stack)));
            }
            else if(array->array[i].symbol == 't')
            {
                pushDouble(stack, tan(topDouble(stack)));
            }
            else if(array->array[i].symbol == '+')
            {
                pushDouble(stack, topDouble(stack) + topDouble(stack));
            }
            else if(array->array[i].symbol == '-')
            {
                pushDouble(stack, -(topDouble(stack) - topDouble(stack)));
            }
            else if(array->array[i].symbol == '*')
            {
                pushDouble(stack, topDouble(stack) * topDouble(stack));
            }
            else if(array->array[i].symbol == '/')
            {
                double d1 = topDouble(stack);
                double d2 = topDouble(stack);
                pushDouble(stack, d2 / d1);
            }
            else
            {
                printf("错误：是否在输入过程中输入了无法解析的符号？\n");
                return 0.0;
            }
        }
    }

    if(stack->top > 1)
    {
        printf("错误：数字与运算符不匹配。\n");
        return 0.0;
    }
    else
    {
        ret = topDouble(stack);
        return ret;
    }
    deleteDoubleStack(stack);
    deletePostfixElementArray(array);
}