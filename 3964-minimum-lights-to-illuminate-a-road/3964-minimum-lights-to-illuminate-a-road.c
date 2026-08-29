#include <stdlib.h>

int minLights(int* lights, int lightsSize) {
    int n = lightsSize;

    int *diff = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        int v = lights[i];

        if (v > 0) {
            int l = i - v;
            int r = i + v;

            if (l < 0)
                l = 0;

            if (r >= n)
                r = n - 1;

            diff[l]++;

            if (r + 1 < n)
                diff[r + 1]--;
        }
    }

    int active = 0;
    int empty = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        active += diff[i];

        if (active == 0) {
            empty++;
        } else {
            ans += (empty + 2) / 3;
            empty = 0;
        }
    }

    ans += (empty + 2) / 3;

    free(diff);

    return ans;
}