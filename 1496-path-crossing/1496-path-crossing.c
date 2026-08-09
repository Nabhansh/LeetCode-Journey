#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} Point;

bool isPathCrossing(char* path)
{
    int n = strlen(path);

    Point *visited =
        malloc((n + 1) * sizeof(Point));

    int count = 1;

    visited[0].x = 0;
    visited[0].y = 0;

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        if (path[i] == 'N')
            y++;

        else if (path[i] == 'S')
            y--;

        else if (path[i] == 'E')
            x++;

        else if (path[i] == 'W')
            x--;

        for (int j = 0; j < count; j++)
        {
            if (visited[j].x == x &&
                visited[j].y == y)
            {
                free(visited);
                return true;
            }
        }

        visited[count].x = x;
        visited[count].y = y;

        count++;
    }

    free(visited);

    return false;
}