#include <stdlib.h>

int countCoveredBuildings(
    int n,
    int **buildings,
    int buildingsSize,
    int *buildingsColSize
)
{
    /*
        rowMin[x] = minimum y-coordinate
                   of a building in row x

        rowMax[x] = maximum y-coordinate
                   of a building in row x
    */

    int *rowMin = (int *)malloc((n + 1) * sizeof(int));
    int *rowMax = (int *)malloc((n + 1) * sizeof(int));

    /*
        colMin[y] = minimum x-coordinate
                   of a building in column y

        colMax[y] = maximum x-coordinate
                   of a building in column y
    */

    int *colMin = (int *)malloc((n + 1) * sizeof(int));
    int *colMax = (int *)malloc((n + 1) * sizeof(int));

    /*
        Initialize.
    */

    for (int i = 1; i <= n; i++)
    {
        rowMin[i] = n + 1;
        rowMax[i] = 0;

        colMin[i] = n + 1;
        colMax[i] = 0;
    }

    /*
        Store min/max coordinates.
    */

    for (int i = 0; i < buildingsSize; i++)
    {
        int x = buildings[i][0];
        int y = buildings[i][1];

        /*
            Same row.
        */

        if (y < rowMin[x])
            rowMin[x] = y;

        if (y > rowMax[x])
            rowMax[x] = y;

        /*
            Same column.
        */

        if (x < colMin[y])
            colMin[y] = x;

        if (x > colMax[y])
            colMax[y] = x;
    }

    /*
        Check every building.
    */

    int answer = 0;

    for (int i = 0; i < buildingsSize; i++)
    {
        int x = buildings[i][0];
        int y = buildings[i][1];

        /*
            Left and right buildings exist
            if y is strictly between
            rowMin[x] and rowMax[x].
        */

        int hasLeftAndRight =
            rowMin[x] < y &&
            y < rowMax[x];

        /*
            Above and below buildings exist
            if x is strictly between
            colMin[y] and colMax[y].
        */

        int hasAboveAndBelow =
            colMin[y] < x &&
            x < colMax[y];

        if (hasLeftAndRight && hasAboveAndBelow)
        {
            answer++;
        }
    }

    free(rowMin);
    free(rowMax);
    free(colMin);
    free(colMax);

    return answer;
}