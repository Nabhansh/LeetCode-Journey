#include <stdlib.h>

int numSpecial(int** mat, int matSize, int* matColSize)
{
    int rows = matSize;
    int cols = matColSize[0];

    int* rowCount = (int*)calloc(rows, sizeof(int));
    int* colCount = (int*)calloc(cols, sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 1)
            {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 1 &&
                rowCount[i] == 1 &&
                colCount[j] == 1)
            {
                result++;
            }
        }
    }

    free(rowCount);
    free(colCount);

    return result;
}