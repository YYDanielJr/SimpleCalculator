#include <stdio.h>
#include <string.h>
#include "../include/control.h"
#include "../include/stack.h"
#include "../include/calculate.h"
#include "../include/filewriter.h"

int main() 
{
    char input[1024] = {0};
    FILE* fp = openHistoryFile();
    do
    {
        memset(input, 0, 1024);
        // fflush(stdin);   （在最新的msvc下不起作用）
        rewind(stdin);
        gets(input);
        writeString(fp, input);
        toLowerCase(input);
        simplifySyntax(input);
        double result = calculate(input);
        printf("%lf", result);
        writeDouble(fp, result);
    } while (ask() == 'y');
    closeHistoryFile(fp);
    return 0;
}
