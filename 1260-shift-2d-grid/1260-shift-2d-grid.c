/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(
    int** grid, int gridSize, int* gridColSize, int k,
    int* returnSize, int** returnColumnSizes
) {
    int i, j, m, n=gridSize*gridColSize[0];
    int w=gridColSize[0], h=gridSize; k%=n;

    *returnColumnSizes=malloc((*returnSize=h)*sizeof(int));
    int **result=malloc(*returnSize*sizeof(int*));

    for(i=0; i<h; i++) {
        result[i]=malloc(((*returnColumnSizes)[i]=w)*sizeof(int));
        for(j=0; j<w; j++){ m=(i*w+j-k+n)%n; result[i][j]=grid[m/w][m%w]; }
    }

    return result;
}