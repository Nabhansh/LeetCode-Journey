int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);

    int **ans = malloc(n * sizeof(int *));
    *returnColumnSizes = malloc(n * sizeof(int));
    *returnSize = 0;

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;

        if (j - i >= 3) {
            ans[*returnSize] = malloc(2 * sizeof(int));
            ans[*returnSize][0] = i;
            ans[*returnSize][1] = j - 1;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }

        i = j;
    }

    return ans;
}