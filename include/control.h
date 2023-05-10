#pragma once
#include <stdio.h>
#include "../include/stack.h"
#include <string.h>
char ask();

// 将sin、cos和tan转化为s、c和t，便于识别。
void simplifySyntax(char*);
void toLowerCase(char*);