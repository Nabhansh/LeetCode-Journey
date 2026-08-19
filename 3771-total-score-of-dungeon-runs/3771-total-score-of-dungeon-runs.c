#include <stdlib.h>

long long totalScore(int hp, int* damage, int damageSize, int* requirement, int requirementSize) {
    int n = damageSize;
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));

    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + damage[i];

    long long ans = 1LL * n * (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        long long low = prefix[i + 1] + requirement[i] - hp;

        if (low > 0) {
            int left = 0;
            int right = i + 1;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (prefix[mid] >= low)
                    right = mid;
                else
                    left = mid + 1;
            }

            ans -= left;
        }
    }

    free(prefix);
    return ans;
}