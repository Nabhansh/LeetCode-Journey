int findMaxVal(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize, int* diff, int diffSize) {
    int *a = malloc(n * sizeof(int));
    int *limit = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        limit[i] = 1000000000;

    limit[0] = 0;

    for (int i = 0; i < restrictionsSize; i++)
        limit[restrictions[i][0]] = restrictions[i][1];

    a[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int v = a[i] + diff[i];
        a[i + 1] = v < limit[i + 1] ? v : limit[i + 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        int v = a[i + 1] + diff[i];
        if (v < a[i])
            a[i] = v;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > ans)
            ans = a[i];
    }

    free(a);
    free(limit);

    return ans;
}