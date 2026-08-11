#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* makeGood(char* s)
{
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++)
    {
        if (top > 0 &&
            tolower(stack[top - 1]) == tolower(s[i]) &&
            stack[top - 1] != s[i])
        {
            top--;
        }
        else
        {
            stack[top++] = s[i];
        }
    }

    stack[top] = '\0';

    return stack;
}