typedef long long ll;

long long shiftDistance(char* s, char* t, int* nextCost, int nextCostSize,
                        int* previousCost, int previousCostSize) {

    ll ans = 0;

    for (int i = 0; s[i]; i++) {

        ll forward = 0;
        ll backward = 0;

        int cur = s[i] - 'a';
        int target = t[i] - 'a';

        int x = cur;
        while (x != target) {
            forward += nextCost[x];
            x = (x + 1) % 26;
        }

        x = cur;
        while (x != target) {
            x = (x + 25) % 26;
            backward += previousCost[(x + 1) % 26];
        }

        ans += (forward < backward) ? forward : backward;
    }

    return ans;
}