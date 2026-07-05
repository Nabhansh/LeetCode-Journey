int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    int *ans = malloc(n * sizeof(int));

    int prev = -n;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) prev = i;
        ans[i] = i - prev;
    }

    prev = 2 * n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) prev = i;
        if (prev - i < ans[i])
            ans[i] = prev - i;
    }

    *returnSize = n;
    return ans;
}