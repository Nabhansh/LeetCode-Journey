#include <stdlib.h>
#include <string.h>

char** shortestSubstrings(char** arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    char **ans = (char **)malloc(arrSize * sizeof(char *));

    for (int i = 0; i < arrSize; i++) {
        ans[i] = (char *)malloc(25);
        ans[i][0] = '\0';

        int len = strlen(arr[i]);

        for (int l = 1; l <= len && ans[i][0] == '\0'; l++) {

            char best[25];
            best[0] = '\0';

            for (int s = 0; s + l <= len; s++) {

                char sub[25];
                strncpy(sub, arr[i] + s, l);
                sub[l] = '\0';

                int ok = 1;

                for (int j = 0; j < arrSize && ok; j++) {
                    if (j == i)
                        continue;

                    if (strstr(arr[j], sub))
                        ok = 0;
                }

                if (ok) {
                    if (best[0] == '\0' || strcmp(sub, best) < 0)
                        strcpy(best, sub);
                }
            }

            if (best[0])
                strcpy(ans[i], best);
        }
    }

    return ans;
}