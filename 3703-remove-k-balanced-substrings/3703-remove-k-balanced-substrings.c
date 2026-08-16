#include <stdlib.h>
#include <string.h>

char* removeSubstring(char *s, int k)
{
    int n = strlen(s);

    char *stackChar = (char *)malloc((n + 1) * sizeof(char));
    int *stackCount = (int *)malloc((n + 1) * sizeof(int));

    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        // Same character as top -> increase count
        if (top >= 0 && stackChar[top] == c)
        {
            stackCount[top]++;
        }
        else
        {
            top++;
            stackChar[top] = c;
            stackCount[top] = 1;
        }

        /*
         * If we have:
         *
         *    '(' run >= k
         *    ')' run == k
         *
         * remove k '(' and k ')'.
         */
        if (c == ')' && top >= 1)
        {
            if (stackChar[top] == ')' &&
                stackCount[top] == k &&
                stackChar[top - 1] == '(' &&
                stackCount[top - 1] >= k)
            {
                // Remove ')' run
                top--;

                // Remove k '('
                stackCount[top] -= k;

                if (stackCount[top] == 0)
                    top--;
            }
        }
    }

    // Construct result
    int resultLength = 0;

    for (int i = 0; i <= top; i++)
        resultLength += stackCount[i];

    char *result = (char *)malloc((resultLength + 1) * sizeof(char));

    int pos = 0;

    for (int i = 0; i <= top; i++)
    {
        for (int j = 0; j < stackCount[i]; j++)
            result[pos++] = stackChar[i];
    }

    result[pos] = '\0';

    free(stackChar);
    free(stackCount);

    return result;
}