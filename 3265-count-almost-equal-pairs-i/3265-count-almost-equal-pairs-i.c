#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countPairs(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    // Frequency map (values <= 1e6)
    int *cnt = (int *)calloc(1000001, sizeof(int));
    int ans = 0;

    for (int idx = 0; idx < numsSize; idx++) {
        char s[8];
        sprintf(s, "%d", nums[idx]);
        int len = strlen(s);

        int vis[25];
        int visCnt = 0;

        // Original number
        vis[visCnt++] = nums[idx];

        // All one-swap numbers
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;

                int x = atoi(s);

                int found = 0;
                for (int k = 0; k < visCnt; k++) {
                    if (vis[k] == x) {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    vis[visCnt++] = x;

                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }

        for (int i = 0; i < visCnt; i++)
            ans += cnt[vis[i]];

        cnt[nums[idx]]++;
    }

    free(cnt);
    return ans;
}