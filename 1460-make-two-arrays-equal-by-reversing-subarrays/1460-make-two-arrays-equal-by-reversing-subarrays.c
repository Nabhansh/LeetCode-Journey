#include <stdbool.h>

bool canBeEqual(
    int* target,
    int targetSize,
    int* arr,
    int arrSize
)
{
    if (targetSize != arrSize)
        return false;

    int freq[1001] = {0};

    for (int i = 0; i < targetSize; i++)
    {
        freq[target[i]]++;
        freq[arr[i]]--;
    }

    for (int i = 1; i <= 1000; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true;
}