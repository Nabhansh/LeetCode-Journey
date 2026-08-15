#include <stdlib.h>

int** generateSchedule(int n, int* returnSize, int** returnColumnSizes)
{
    if (n < 5)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int total = n * (n - 1);
    int **ans = malloc(total * sizeof(int *));
    *returnColumnSizes = malloc(total * sizeof(int));

    int **rem = malloc(n * sizeof(int *));
    int *home = malloc(n * sizeof(int));
    int *away = malloc(n * sizeof(int));
    int *last = malloc(n * sizeof(int));
    int *run = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        rem[i] = calloc(n, sizeof(int));
        home[i] = n - 1;
        away[i] = n - 1;
        last[i] = -1;
        run[i] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                rem[i][j] = 1;

    int prevA = -1;
    int prevB = -1;

    for (int d = 0; d < total; d++)
    {
        int bu = -1;
        int bv = -1;
        int best = -1;

        for (int u = 0; u < n; u++)
        {
            if (u == prevA || u == prevB || home[u] == 0)
                continue;

            if (last[u] == 0 && run[u] >= 3)
                continue;

            for (int v = 0; v < n; v++)
            {
                if (v == u || v == prevA || v == prevB)
                    continue;

                if (away[v] == 0)
                    continue;

                if (last[v] == 1 && run[v] >= 3)
                    continue;

                if (!rem[u][v])
                    continue;

                int score = (home[u] << 16) ^ away[v];

                if (score > best)
                {
                    best = score;
                    bu = u;
                    bv = v;
                }
            }
        }

        if (bu == -1)
        {
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }

        ans[d] = malloc(2 * sizeof(int));
        ans[d][0] = bu;
        ans[d][1] = bv;
        (*returnColumnSizes)[d] = 2;

        rem[bu][bv] = 0;
        home[bu]--;
        away[bv]--;

        if (last[bu] == 0)
            run[bu]++;
        else
        {
            last[bu] = 0;
            run[bu] = 1;
        }

        if (last[bv] == 1)
            run[bv]++;
        else
        {
            last[bv] = 1;
            run[bv] = 1;
        }

        prevA = bu;
        prevB = bv;
    }

    for (int i = 0; i < n; i++)
        free(rem[i]);

    free(rem);
    free(home);
    free(away);
    free(last);
    free(run);

    *returnSize = total;
    return ans;
}