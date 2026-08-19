long long minMoves(int* balance, int balanceSize) {
    long long sum = 0;

    for (int i = 0; i < balanceSize; i++)
        sum += balance[i];

    if (sum < 0)
        return -1;

    int idx = -1;

    for (int i = 0; i < balanceSize; i++) {
        if (balance[i] < 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1)
        return 0;

    long long need = -(long long)balance[idx];
    long long ans = 0;

    for (int d = 1; d < balanceSize && need > 0; d++) {
        int left = (idx - d + balanceSize) % balanceSize;
        int right = (idx + d) % balanceSize;

        long long take = balance[left] < need ? balance[left] : need;
        if (take > 0) {
            need -= take;
            ans += take * d;
        }

        if (need > 0) {
            take = balance[right] < need ? balance[right] : need;
            if (take > 0) {
                need -= take;
                ans += take * d;
            }
        }
    }

    return ans;
}