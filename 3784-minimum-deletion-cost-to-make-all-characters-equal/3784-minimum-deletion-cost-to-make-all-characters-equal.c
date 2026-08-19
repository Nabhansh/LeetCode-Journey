long long minCost(char* s, int* cost, int costSize) {
    long long total = 0;
    long long sum[26] = {0};

    for (int i = 0; i < costSize; i++) {
        total += cost[i];
        sum[s[i] - 'a'] += cost[i];
    }

    long long best = 0;

    for (int i = 0; i < 26; i++) {
        if (sum[i] > best)
            best = sum[i];
    }

    return total - best;
}