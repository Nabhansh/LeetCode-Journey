#include <stdlib.h>

typedef struct {
    int limit;
    int value;
} Pair;

int compare(const void *a, const void *b)
{
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;

    // First sort by limit
    if (p1->limit != p2->limit)
        return p1->limit - p2->limit;

    // For same limit, larger value first
    return p2->value - p1->value;
}

long long maxTotal(int* value, int valueSize,
                   int* limit, int limitSize)
{
    Pair *arr = malloc(valueSize * sizeof(Pair));

    for (int i = 0; i < valueSize; i++)
    {
        arr[i].value = value[i];
        arr[i].limit = limit[i];
    }

    qsort(arr, valueSize, sizeof(Pair), compare);

    long long answer = 0;

    int i = 0;

    while (i < valueSize)
    {
        int currentLimit = arr[i].limit;
        int count = 0;

        // Process all elements having the same limit
        while (i < valueSize &&
               arr[i].limit == currentLimit)
        {
            if (count < currentLimit)
                answer += arr[i].value;

            count++;
            i++;
        }
    }

    free(arr);

    return answer;
}