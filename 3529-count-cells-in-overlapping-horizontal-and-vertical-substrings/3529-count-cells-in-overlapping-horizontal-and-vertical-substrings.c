#include <stdlib.h>
#include <string.h>

static void buildLPS(char *pattern, int m, int *lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

static void findMatches(
    char *text,
    int n,
    char *pattern,
    int m,
    int *diff
)
{
    int *lps = (int *)malloc(m * sizeof(int));

    buildLPS(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;

            if (j == m)
            {
                int start = i - m;
                int end = i - 1;

                diff[start]++;
                diff[end + 1]--;

                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    free(lps);
}

int countCells(
    char **grid,
    int gridSize,
    int *gridColSize,
    char *pattern
)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    int total = rows * cols;
    int patternLen = strlen(pattern);

    /*
        Horizontal flattened grid:
        
        abc
        def
        ghi

        becomes:

        abcdefghi
    */

    char *horizontal = (char *)malloc(total + 1);

    int k = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            horizontal[k++] = grid[i][j];
        }
    }

    horizontal[total] = '\0';

    /*
        Vertical flattened grid:

        abc
        def
        ghi

        becomes:

        adgbehcfi
    */

    char *vertical = (char *)malloc(total + 1);

    k = 0;

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            vertical[k++] = grid[i][j];
        }
    }

    vertical[total] = '\0';

    /*
        Difference arrays.
    */

    int *horizontalDiff =
        (int *)calloc(total + 1, sizeof(int));

    int *verticalDiff =
        (int *)calloc(total + 1, sizeof(int));

    /*
        Find all horizontal occurrences.
    */

    findMatches(
        horizontal,
        total,
        pattern,
        patternLen,
        horizontalDiff
    );

    /*
        Find all vertical occurrences.
    */

    findMatches(
        vertical,
        total,
        pattern,
        patternLen,
        verticalDiff
    );

    /*
        Convert difference arrays into
        actual coverage arrays.
    */

    int *horizontalCovered =
        (int *)calloc(total, sizeof(int));

    int *verticalCovered =
        (int *)calloc(total, sizeof(int));

    int current = 0;

    for (int i = 0; i < total; i++)
    {
        current += horizontalDiff[i];
        horizontalCovered[i] = current;
    }

    current = 0;

    for (int i = 0; i < total; i++)
    {
        current += verticalDiff[i];
        verticalCovered[i] = current;
    }

    /*
        Count cells covered horizontally
        AND vertically.
    */

    int answer = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            /*
                Horizontal index:
                i * cols + j

                Vertical index:
                j * rows + i
            */

            int horizontalIndex = i * cols + j;
            int verticalIndex = j * rows + i;

            if (horizontalCovered[horizontalIndex] > 0 &&
                verticalCovered[verticalIndex] > 0)
            {
                answer++;
            }
        }
    }

    free(horizontal);
    free(vertical);
    free(horizontalDiff);
    free(verticalDiff);
    free(horizontalCovered);
    free(verticalCovered);

    return answer;
}