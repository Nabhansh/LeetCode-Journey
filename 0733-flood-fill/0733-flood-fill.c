void dfs(int** image, int imageSize, int* imageColSize,
         int r, int c, int oldColor, int newColor) {

    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[0])
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(image, imageSize, imageColSize, r + 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    *returnSize = imageSize;

    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));

    for (int i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    int oldColor = image[sr][sc];

    if (oldColor != color)
        dfs(image, imageSize, imageColSize, sr, sc, oldColor, color);

    return image;
}