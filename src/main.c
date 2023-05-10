#include <stdio.h>
#include <string.h>
#include "../include/control.h"
#include "../include/stack.h"
#include "../include/calculate.h"

int main() 
{
    char input[1024] = {0};
    do
    {
        memset(input, 0, 1024);
        // fflush(stdin);   （在最新的msvc下不起作用）
        rewind(stdin);
        gets(input);
        toLowerCase(input);
        simplifySyntax(input);
        printf("%lf", calculate(input));
    } while (ask() == 'y');
    
    return 0;
}
