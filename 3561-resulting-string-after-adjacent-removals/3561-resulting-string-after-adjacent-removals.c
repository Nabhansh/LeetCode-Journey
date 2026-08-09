#include <stdlib.h>
#include <string.h>

char* resultingString(char* s)
{
    int n = strlen(s);

    /*
        Stack can contain at most n characters.
    */

    char *stack = malloc((n + 1) * sizeof(char));

    int top = 0;

    for (int i = 0; i < n; i++)
    {
        char current = s[i];

        if (top > 0)
        {
            char previous = stack[top - 1];

            int difference = abs(previous - current);

            /*
                Consecutive alphabet characters:

                a-b => 1
                b-c => 1
                ...
                y-z => 1

                Circular:

                a-z => 25
            */

            if (difference == 1 ||
                difference == 25)
            {
                /*
                    Remove previous character.
                */

                top--;

                continue;
            }
        }

        /*
            Otherwise push current character.
        */

        stack[top++] = current;
    }

    /*
        Null terminate the result.
    */

    stack[top] = '\0';

    return stack;
}