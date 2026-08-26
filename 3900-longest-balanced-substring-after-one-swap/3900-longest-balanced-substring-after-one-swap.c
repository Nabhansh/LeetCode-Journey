#include <stdlib.h>
#include <string.h>

int longestBalanced(char* s) {
    int n = strlen(s);
    int cnt0 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cnt0++;
    }

    int cnt1 = n - cnt0;
    int size = 2 * n + 5;
    int offset = n + 2;

    int* first = malloc(size * sizeof(int));
    int* second = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        first[i] = -2;
        second[i] = -2;
    }

    first[offset] = -1;

    int pre = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        pre += (s[i] == '1') ? 1 : -1;

        int idx = pre + offset;

        if (first[idx] == -2) {
            first[idx] = i;
        } else if (second[idx] == -2) {
            second[idx] = i;
        }

        if (first[idx] != -2) {
            int len = i - first[idx];

            if (len > ans)
                ans = len;
        }

        int idx1 = pre - 2 + offset;

        if (idx1 >= 0 && idx1 < size && first[idx1] != -2) {
            int p = first[idx1];
            int len = i - p;

            if ((len - 2) / 2 < cnt0) {
                if (len > ans)
                    ans = len;
            } else if (second[idx1] != -2) {
                len = i - second[idx1];

                if (len > ans)
                    ans = len;
            }
        }

        int idx2 = pre + 2 + offset;

        if (idx2 >= 0 && idx2 < size && first[idx2] != -2) {
            int p = first[idx2];
            int len = i - p;

            if ((len - 2) / 2 < cnt1) {
                if (len > ans)
                    ans = len;
            } else if (second[idx2] != -2) {
                len = i - second[idx2];

                if (len > ans)
                    ans = len;
            }
        }
    }

    free(first);
    free(second);

    return ans;
}