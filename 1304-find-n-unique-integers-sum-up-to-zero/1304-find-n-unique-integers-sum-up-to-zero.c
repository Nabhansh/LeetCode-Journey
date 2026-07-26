int* sumZero(int n, int* returnSize) {

    *returnSize = n;

    int *ans = (int *)malloc(n * sizeof(int));

    int idx = 0;

    for (int i = 1; i <= n / 2; i++) {
        ans[idx++] = i;
        ans[idx++] = -i;
    }

    if (n % 2)
        ans[idx] = 0;

    return ans;
}