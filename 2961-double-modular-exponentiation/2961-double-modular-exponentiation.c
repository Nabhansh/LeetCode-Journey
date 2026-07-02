int modPow(long long base, long long exp, int mod) {
    long long res = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return (int)res;
}

int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize,
                    int target, int* returnSize) {

    int* ans = (int*)malloc(variablesSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < variablesSize; i++) {
        int a = variables[i][0];
        int b = variables[i][1];
        int c = variables[i][2];
        int m = variables[i][3];

        int x = modPow(a, b, 10);
        int y = modPow(x, c, m);

        if (y == target)
            ans[(*returnSize)++] = i;
    }

    return ans;
}