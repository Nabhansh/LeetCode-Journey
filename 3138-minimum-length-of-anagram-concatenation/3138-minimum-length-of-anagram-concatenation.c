#include <string.h>

int minAnagramLength(char* s) {
    int n = strlen(s);

    for (int k = 1; k <= n; k++) {
        if (n % k != 0) {
            continue;
        }

        int base[26] = {0};

        for (int i = 0; i < k; i++) {
            base[s[i] - 'a']++;
        }

        int valid = 1;

        for (int start = k; start < n; start += k) {
            int current[26] = {0};

            for (int i = start; i < start + k; i++) {
                current[s[i] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                if (current[j] != base[j]) {
                    valid = 0;
                    break;
                }
            }

            if (!valid) {
                break;
            }
        }

        if (valid) {
            return k;
        }
    }

    return n;
}