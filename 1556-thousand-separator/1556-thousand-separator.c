#include <stdlib.h>
#include <stdio.h>

char* thousandSeparator(int n)
{
    char temp[50];
    sprintf(temp, "%d", n);

    int len = 0;

    while (temp[len] != '\0')
        len++;

    char* result = (char*)malloc(50 * sizeof(char));

    int i = len - 1;
    int j = 0;
    int count = 0;

    while (i >= 0)
    {
        result[j++] = temp[i--];
        count++;

        if (count == 3 && i >= 0)
        {
            result[j++] = '.';
            count = 0;
        }
    }

    result[j] = '\0';

    for (int left = 0, right = j - 1; left < right; left++, right--)
    {
        char t = result[left];
        result[left] = result[right];
        result[right] = t;
    }

    return result;
}