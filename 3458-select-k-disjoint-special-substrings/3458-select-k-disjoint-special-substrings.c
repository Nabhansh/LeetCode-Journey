#include <stdbool.h>
#include <string.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

bool maxSubstringLength(char* s, int k) {
    if (k == 0)
        return true;

    int n = strlen(s);

    int first[26], last[26];
    for (int i = 0; i < 26; i++) {
        first[i] = n;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (first[c] == n)
            first[c] = i;
        last[c] = i;
    }

    int end[26];
    for (int c = 0; c < 26; c++) {
        if (last[c] == -1) {
            end[c] = -1;
            continue;
        }

        int l = first[c];
        int r = last[c];
        bool ok = true;

        for (int i = l; i <= r && ok; i++) {
            int x = s[i] - 'a';
            if (first[x] < l) {
                ok = false;
                break;
            }
            r = max(r, last[x]);
        }

        if (ok && !(l == 0 && r == n - 1))
            end[c] = r;
        else
            end[c] = -1;
    }

    int intervals[26][2];
    int m = 0;

    for (int c = 0; c < 26; c++) {
        if (end[c] != -1) {
            intervals[m][0] = first[c];
            intervals[m][1] = end[c];
            m++;
        }
    }

    /* Sort by ending position */
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (intervals[j][1] < intervals[i][1]) {
                int t0 = intervals[i][0], t1 = intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = t0;
                intervals[j][1] = t1;
            }
        }
    }

    int cnt = 0;
    int lastEnd = -1;

    for (int i = 0; i < m; i++) {
        if (intervals[i][0] > lastEnd) {
            cnt++;
            lastEnd = intervals[i][1];
            if (cnt >= k)
                return true;
        }
    }

    return false;
}