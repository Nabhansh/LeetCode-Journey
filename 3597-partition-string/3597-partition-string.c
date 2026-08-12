#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int child[26];
    int end;
} Node;

char** partitionString(char* s, int* returnSize) {
    int n = strlen(s);
    Node* trie = calloc(n + 1, sizeof(Node));
    char** ans = malloc((n + 1) * sizeof(char*));
    int nodes = 1;
    int count = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        int cur = 0;
        int j = start;

        while (j <= i) {
            int c = s[j] - 'a';

            if (trie[cur].child[c] == 0) {
                trie[cur].child[c] = nodes++;
            }

            cur = trie[cur].child[c];
            j++;

            if (!trie[cur].end) {
                int len = j - start;
                ans[count] = malloc(len + 1);
                memcpy(ans[count], s + start, len);
                ans[count][len] = '\0';
                trie[cur].end = 1;
                count++;
                start = j;
                break;
            }
        }
    }

    *returnSize = count;
    free(trie);
    return ans;
}