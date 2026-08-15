#include <stdlib.h>

int minArrivalsToDiscard(int* arrivals, int arrivalsSize, int w, int m)
{
    int *count = calloc(100001, sizeof(int));
    int *kept = calloc(arrivalsSize, sizeof(int));
    int ans = 0;

    for (int i = 0; i < arrivalsSize; i++)
    {
        if (i >= w)
            count[arrivals[i - w]] -= kept[i - w];

        if (count[arrivals[i]] >= m)
        {
            ans++;
        }
        else
        {
            kept[i] = 1;
            count[arrivals[i]]++;
        }
    }

    free(count);
    free(kept);

    return ans;
}