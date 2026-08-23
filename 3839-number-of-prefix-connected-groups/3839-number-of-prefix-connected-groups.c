#include <stdlib.h>
#include <string.h>

typedef struct {
    int child[26];
    int count;
} TrieNode;

int prefixConnected(char** words, int wordsSize, int k) {
    int maxNodes = wordsSize * k + 1;
    TrieNode* trie = calloc(maxNodes, sizeof(TrieNode));
    int nodes = 1;
    int ans = 0;

    for (int i = 0; i < wordsSize; i++) {
        if ((int)strlen(words[i]) < k)
            continue;

        int cur = 0;

        for (int j = 0; j < k; j++) {
            int c = words[i][j] - 'a';

            if (trie[cur].child[c] == 0) {
                trie[cur].child[c] = nodes++;
            }

            cur = trie[cur].child[c];
        }

        trie[cur].count++;
    }

    for (int i = 1; i < nodes; i++) {
        if (trie[i].count >= 2)
            ans++;
    }

    free(trie);
    return ans;
}