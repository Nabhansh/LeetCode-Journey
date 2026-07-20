#define INF 1000000000

typedef struct Trie {
    struct Trie *next[26];
} Trie;

Trie* newNode() {
    Trie *t = (Trie*)calloc(1, sizeof(Trie));
    return t;
}

void insert(Trie *root, char *s) {
    while (*s) {
        int c = *s - 'a';
        if (!root->next[c])
            root->next[c] = newNode();
        root = root->next[c];
        s++;
    }
}

int n;
char *target;
int memo[5005];

int dfs(int idx, Trie *root) {
    if (idx == n) return 0;
    if (memo[idx] != -1) return memo[idx];

    Trie *cur = root;
    int ans = INF;

    for (int i = idx; i < n; i++) {
        int c = target[i] - 'a';
        if (!cur->next[c]) break;
        cur = cur->next[c];

        int t = dfs(i + 1, root);
        if (t != INF && t + 1 < ans)
            ans = t + 1;
    }

    return memo[idx] = ans;
}

int minValidStrings(char** words, int wordsSize, char* t) {
    Trie *root = newNode();

    for (int i = 0; i < wordsSize; i++)
        insert(root, words[i]);

    target = t;
    n = strlen(t);

    memset(memo, -1, sizeof(memo));

    int ans = dfs(0, root);
    return ans == INF ? -1 : ans;
}