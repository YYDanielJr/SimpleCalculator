#include "../include/control.h"
char ask()
{
    printf("\n\nContinue? \n");
    // fflush(stdin);   新版本的msvc不起效果
    rewind(stdin);
    return getchar();
}

void toLowerCase(char* buffer)
{
    for(int i = 0; i < strlen(buffer); i++)
    {
        if(buffer[i] >= 'A' && buffer[i] <= 'Z')
        {
            buffer[i] += 32;
        }
    }
}

void simplifySyntax(char* buffer)
{
    char* temp = NULL;
    while(temp = strstr(buffer, " "))
    {
        *temp = 0;
        strcat(buffer, ++temp);
        temp = &buffer[strlen(buffer) - 1];
        *(++temp) = 0;
    }
    while(temp = strstr(buffer, "sin"))
    {
        *(++temp) = 0;
        *(++temp) = 0;
        strcat(buffer, ++temp);
        temp = &buffer[strlen(buffer) - 1];
        *(++temp) = 0;
        *(++temp) = 0;
    }
    while(temp = strstr(buffer, "cos"))
    {
        *(++temp) = 0;
        *(++temp) = 0;
        strcat(buffer, ++temp);
        temp = &buffer[strlen(buffer) - 1];
        *(++temp) = 0;
        *(++temp) = 0;
    }
    while(temp = strstr(buffer, "tan"))
    {
        *(++temp) = 0;
        *(++temp) = 0;
        strcat(buffer, ++temp);
        temp = &buffer[strlen(buffer) - 1];
        *(++temp) = 0;
        *(++temp) = 0;
    }
    while(temp = strstr(buffer, "pi"))
    {
        *(++temp) = 0;
        strcat(buffer, ++temp);
        temp = &buffer[strlen(buffer) - 1];
        *(++temp) = 0;
    }
}
