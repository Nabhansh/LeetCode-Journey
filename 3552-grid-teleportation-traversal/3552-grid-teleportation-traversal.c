#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int r;
    int c;
} Node;

int minMoves(char** matrix, int matrixSize)
{
    int m = matrixSize;
    int n = strlen(matrix[0]);

    int total = m * n;

    /*
        dist[i] = minimum distance to cell i
    */
    int *dist = malloc(total * sizeof(int));

    for (int i = 0; i < total; i++)
        dist[i] = INT_MAX;

    /*
        Store all positions of each portal.
        There are only 26 uppercase letters.
    */

    int count[26] = {0};

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            char ch = matrix[r][c];

            if (ch >= 'A' && ch <= 'Z')
                count[ch - 'A']++;
        }
    }

    int **portalR = malloc(26 * sizeof(int *));
    int **portalC = malloc(26 * sizeof(int *));

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            portalR[i] = malloc(count[i] * sizeof(int));
            portalC[i] = malloc(count[i] * sizeof(int));
        }
        else
        {
            portalR[i] = NULL;
            portalC[i] = NULL;
        }
    }

    int index[26] = {0};

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            char ch = matrix[r][c];

            if (ch >= 'A' && ch <= 'Z')
            {
                int x = ch - 'A';

                portalR[x][index[x]] = r;
                portalC[x][index[x]] = c;

                index[x]++;
            }
        }
    }

    /*
        Each portal letter can be used only once.
    */

    int used[26] = {0};

    /*
        0-1 BFS deque.

        We need to be able to add:
            - teleport nodes to FRONT
            - normal moves to BACK

        Maximum useful queue size is O(total).
        Allocate a little extra space.
    */

    Node *deque = malloc((2 * total + 5) * sizeof(Node));

    int left = total;
    int right = total;

    /*
        Start at (0, 0).
    */

    dist[0] = 0;

    deque[right++] = (Node){0, 0};

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (left < right)
    {
        Node cur = deque[left++];

        int r = cur.r;
        int c = cur.c;

        int currentIndex = r * n + c;
        int currentDist = dist[currentIndex];

        /*
            Destination reached.
        */

        if (r == m - 1 && c == n - 1)
        {
            for (int i = 0; i < 26; i++)
            {
                free(portalR[i]);
                free(portalC[i]);
            }

            free(portalR);
            free(portalC);
            free(deque);
            free(dist);

            return currentDist;
        }

        /*
            --------------------------------
            TELEPORTATION: COST = 0
            --------------------------------
        */

        char ch = matrix[r][c];

        if (ch >= 'A' && ch <= 'Z')
        {
            int letter = ch - 'A';

            /*
                Process this portal letter only once.

                This is VERY important for performance.
            */

            if (!used[letter])
            {
                used[letter] = 1;

                for (int i = 0; i < count[letter]; i++)
                {
                    int nr = portalR[letter][i];
                    int nc = portalC[letter][i];

                    int nextIndex = nr * n + nc;

                    if (currentDist < dist[nextIndex])
                    {
                        dist[nextIndex] = currentDist;

                        /*
                            Cost 0 -> push FRONT.
                        */

                        deque[--left] = (Node){nr, nc};
                    }
                }
            }
        }

        /*
            --------------------------------
            NORMAL MOVEMENT: COST = 1
            --------------------------------
        */

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            /*
                Check boundaries.
            */

            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
            {
                continue;
            }

            /*
                Cannot walk into '#'.
            */

            if (matrix[nr][nc] == '#')
                continue;

            int nextIndex = nr * n + nc;

            /*
                Normal movement costs 1.
            */

            if (currentDist + 1 < dist[nextIndex])
            {
                dist[nextIndex] = currentDist + 1;

                /*
                    Cost 1 -> push BACK.
                */

                deque[right++] = (Node){nr, nc};
            }
        }
    }

    /*
        Destination cannot be reached.
    */

    for (int i = 0; i < 26; i++)
    {
        free(portalR[i]);
        free(portalC[i]);
    }

    free(portalR);
    free(portalC);
    free(deque);
    free(dist);

    return -1;
}