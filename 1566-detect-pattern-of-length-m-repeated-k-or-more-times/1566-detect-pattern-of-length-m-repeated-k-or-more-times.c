#include <stdbool.h>

bool containsPattern(int* arr, int arrSize, int m, int k)
{
    int length = m * k;

    for (int i = length - 1; i < arrSize; i++)
    {
        bool found = true;

        for (int j = 0; j < length - m; j++)
        {
            if (arr[i - length + 1 + j] !=
                arr[i - length + 1 + j + m])
            {
                found = false;
                break;
            }
        }

        if (found)
            return true;
    }

    return false;
}