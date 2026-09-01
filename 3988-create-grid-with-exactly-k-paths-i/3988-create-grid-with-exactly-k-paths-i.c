char** createGrid(int m, int n, int k, int* returnSize) {
    *returnSize = 0;

    if (k == 1) {
        char** ans = malloc(m * sizeof(char*));
        for (int i = 0; i < m; i++) {
            ans[i] = malloc((n + 1) * sizeof(char));
            for (int j = 0; j < n; j++)
                ans[i][j] = (i == 0 || j == n - 1) ? '.' : '#';
            ans[i][n] = '\0';
        }
        *returnSize = m;
        return ans;
    }

    if (m == 1 || n == 1)
        return NULL;

    char** ans = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        ans[i] = malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++)
            ans[i][j] = '#';
        ans[i][n] = '\0';
    }

    if (m == 2) {
        if (n < k)
            return NULL;

        for (int j = 0; j < n; j++)
            ans[0][j] = '.';

        for (int j = n - k; j < n; j++)
            ans[1][j] = '.';

        *returnSize = m;
        return ans;
    }

    if (n == 2) {
        if (m < k)
            return NULL;

        for (int i = 0; i < m; i++)
            ans[i][0] = '.';

        for (int i = m - k; i < m; i++)
            ans[i][1] = '.';

        *returnSize = m;
        return ans;
    }

    if (k == 2) {
        for (int j = 0; j < n; j++)
            ans[0][j] = '.';

        for (int i = 0; i < m; i++)
            ans[i][n - 1] = '.';

        ans[1][n - 2] = '.';
    } else if (k == 3) {
        for (int j = 0; j < n; j++)
            ans[0][j] = '.';

        for (int i = 0; i < m; i++)
            ans[i][n - 1] = '.';

        ans[1][n - 2] = '.';
        ans[2][n - 2] = '.';
    } else {
        ans[0][0] = '.';
        ans[0][1] = '.';
        ans[1][0] = '.';
        ans[1][1] = '.';
        ans[1][2] = '.';
        ans[2][1] = '.';
        ans[2][2] = '.';

        for (int j = 2; j < n; j++)
            ans[2][j] = '.';

        for (int i = 2; i < m; i++)
            ans[i][n - 1] = '.';
    }

    *returnSize = m;
    return ans;
}