#include <stdlib.h>

int* countTasks(int* tasks, int tasksSize, int* shifts, int shiftsSize, int* returnSize) {
    long long* pref = malloc((tasksSize + 1) * sizeof(long long));
    int* ans = malloc(shiftsSize * sizeof(int));

    pref[0] = 0;
    for (int i = 0; i < tasksSize; i++)
        pref[i + 1] = pref[i] + tasks[i];

    int i = 0;
    long long cur = 0;

    for (int j = 0; j < shiftsSize; j++) {
        long long need = tasks[i] - cur;

        if ((long long)shifts[j] < need) {
            cur += shifts[j];
            ans[j] = tasksSize - i;
        } else {
            long long t = shifts[j] - need;

            if (t >= pref[tasksSize] - pref[i + 1]) {
                i = 0;
                cur = 0;
                ans[j] = 0;
            } else {
                int l = i + 1, r = tasksSize;

                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (t < pref[mid + 1] - pref[i + 1])
                        r = mid;
                    else
                        l = mid + 1;
                }

                cur = t - (pref[l] - pref[i + 1]);
                i = l;
                ans[j] = tasksSize - i;
            }
        }
    }

    free(pref);
    *returnSize = shiftsSize;
    return ans;
}