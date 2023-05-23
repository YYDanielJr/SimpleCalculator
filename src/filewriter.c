#include "../include/filewriter.h"

FILE* openHistoryFile()
{
    FILE* fp = fopen("History.txt", "a");
    return fp;
}
void closeHistoryFile(FILE* fp)
{
    if(fp)
    {
        fclose(fp);
        fp = NULL;
    }
}
void writeString(FILE* fp, char* str)
{
    if(fp)
    {
        fprintf(fp, "%s\n", str);
    }
}

void writeDouble(FILE* fp, double number)
{
    if(fp)
    {
        fprintf(fp, "--> %lf\n", number);
    }
}