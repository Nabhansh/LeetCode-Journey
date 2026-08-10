#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r;
    int c;
    int energy;
    int mask;
    int dist;
} State;

int minMoves(char** classroom, int classroomSize, int energy)
{
    int m = classroomSize;
    int n = strlen(classroom[0]);

    int startR = 0;
    int startC = 0;

    int litterId[20][20];
    memset(litterId, -1, sizeof(litterId));

    int litterCount = 0;

    /* Find starting position and number every litter */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (classroom[i][j] == 'S')
            {
                startR = i;
                startC = j;
            }
            else if (classroom[i][j] == 'L')
            {
                litterId[i][j] = litterCount++;
            }
        }
    }

    /* No litter to collect */
    if (litterCount == 0)
        return 0;

    int masks = 1 << litterCount;

    /*
        State count:
        row × column × energy × mask
    */
    int totalStates = m * n * (energy + 1) * masks;

    bool *visited = calloc(totalStates, sizeof(bool));
    State *queue = malloc(totalStates * sizeof(State));

    int front = 0;
    int rear = 0;

    /*
        mask = 0 means no litter collected
    */
    int startMask = 0;

    int startIndex =
        (((startR * n + startC) * (energy + 1) + energy)
        * masks) + startMask;

    visited[startIndex] = true;

    queue[rear++] = (State){
        startR,
        startC,
        energy,
        startMask,
        0
    };

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int fullMask = (1 << litterCount) - 1;

    while (front < rear)
    {
        State cur = queue[front++];

        /* All litter collected */
        if (cur.mask == fullMask)
        {
            free(visited);
            free(queue);
            return cur.dist;
        }

        /* Cannot move with zero energy */
        if (cur.energy == 0)
            continue;

        for (int d = 0; d < 4; d++)
        {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];

            /* Outside grid */
            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
                continue;

            /* Obstacle */
            if (classroom[nr][nc] == 'X')
                continue;

            int newEnergy = cur.energy - 1;
            int newMask = cur.mask;

            /* Collect litter */
            if (classroom[nr][nc] == 'L')
            {
                int id = litterId[nr][nc];
                newMask |= (1 << id);
            }

            /* Reset energy */
            if (classroom[nr][nc] == 'R')
            {
                newEnergy = energy;
            }

            int index =
                (((nr * n + nc) * (energy + 1) + newEnergy)
                * masks) + newMask;

            if (!visited[index])
            {
                visited[index] = true;

                queue[rear++] = (State){
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    cur.dist + 1
                };
            }
        }
    }

    free(visited);
    free(queue);

    return -1;
}