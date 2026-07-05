int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int n = imageSize;
    int m = imageColSize[0];

    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));

    int **ans = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        ans[i] = malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;

        for (int j = 0; j < m; j++)
            ans[i][j] = image[i][m - 1 - j] ^ 1;
    }

    return ans;
}