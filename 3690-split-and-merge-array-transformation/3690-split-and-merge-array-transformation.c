#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int a[6];
    int d;
} State;

uint64_t encode(int *a, int n)
{
    uint64_t h = 1469598103934665603ULL;

    for (int i = 0; i < n; i++)
    {
        uint32_t x = (uint32_t)(a[i] + 100000);
        h ^= x;
        h *= 1099511628211ULL;
    }

    return h;
}

int minSplitMerge(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int n = nums1Size;

    if (memcmp(nums1, nums2, n * sizeof(int)) == 0)
        return 0;

    State queue[1000];
    uint64_t table[2048];

    memset(table, 0, sizeof(table));

    int front = 0;
    int back = 0;

    memcpy(queue[back].a, nums1, n * sizeof(int));
    queue[back].d = 0;

    uint64_t startHash = encode(nums1, n);
    int p = startHash & 2047;

    while (table[p] != 0)
        p = (p + 1) & 2047;

    table[p] = startHash;
    back++;

    while (front < back)
    {
        State cur = queue[front++];

        for (int l = 0; l < n; l++)
        {
            for (int r = l; r < n; r++)
            {
                int len = r - l + 1;

                if (len == n)
                    continue;

                int block[6];
                int rest[6];

                int bc = 0;
                int rc = 0;

                for (int i = l; i <= r; i++)
                    block[bc++] = cur.a[i];

                for (int i = 0; i < l; i++)
                    rest[rc++] = cur.a[i];

                for (int i = r + 1; i < n; i++)
                    rest[rc++] = cur.a[i];

                for (int pos = 0; pos <= rc; pos++)
                {
                    if (pos == l)
                        continue;

                    int next[6];
                    int k = 0;

                    for (int i = 0; i < pos; i++)
                        next[k++] = rest[i];

                    for (int i = 0; i < bc; i++)
                        next[k++] = block[i];

                    for (int i = pos; i < rc; i++)
                        next[k++] = rest[i];

                    if (memcmp(next, nums2, n * sizeof(int)) == 0)
                        return cur.d + 1;

                    uint64_t h = encode(next, n);
                    int idx = h & 2047;

                    while (table[idx] != 0 && table[idx] != h)
                        idx = (idx + 1) & 2047;

                    if (table[idx] == h)
                        continue;

                    table[idx] = h;

                    memcpy(queue[back].a, next, n * sizeof(int));
                    queue[back].d = cur.d + 1;
                    back++;
                }
            }
        }
    }

    return -1;
}