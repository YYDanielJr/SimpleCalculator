#pragma once
#include <stdio.h>

FILE* openHistoryFile();
void closeHistoryFile(FILE*);
void writeString(FILE*, char*);
void writeDouble(FILE*, double);