int minFlips(char* s) {
    int n = strlen(s);
    int ones = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            ones++;
    }

    int zeros = n - ones;

    int ans = zeros;

    int one = ones > 0 ? ones - 1 : 0;
    if (one < ans)
        ans = one;

    if (n >= 2) {
        int cost = 0;

        if (s[0] == '0')
            cost++;

        if (s[n - 1] == '0')
            cost++;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1')
                cost++;
        }

        if (cost < ans)
            ans = cost;
    }

    return ans;
}