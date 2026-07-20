int numEquivDominoPairs(int** dominoes, int dominoesSize,
                        int* dominoesColSize) {

    int cnt[100] = {0};
    int ans = 0;

    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];

        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        int key = a * 10 + b;
        ans += cnt[key];
        cnt[key]++;
    }

    return ans;
}