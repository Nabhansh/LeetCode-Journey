typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

long long maxScore(int* nums, int numsSize) {

    int n = numsSize;

    if (n == 1)
        return (long long)nums[0] * nums[0];

    ll *preG = malloc(sizeof(ll) * n);
    ll *sufG = malloc(sizeof(ll) * n);
    ll *preL = malloc(sizeof(ll) * n);
    ll *sufL = malloc(sizeof(ll) * n);

    preG[0] = nums[0];
    preL[0] = nums[0];

    for (int i = 1; i < n; i++) {
        preG[i] = gcd(preG[i - 1], nums[i]);
        preL[i] = lcm(preL[i - 1], nums[i]);
    }

    sufG[n - 1] = nums[n - 1];
    sufL[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        sufG[i] = gcd(sufG[i + 1], nums[i]);
        sufL[i] = lcm(sufL[i + 1], nums[i]);
    }

    ll ans = preG[n - 1] * preL[n - 1];

    for (int i = 0; i < n; i++) {

        ll g, l;

        if (i == 0) {
            g = sufG[1];
            l = sufL[1];
        } else if (i == n - 1) {
            g = preG[n - 2];
            l = preL[n - 2];
        } else {
            g = gcd(preG[i - 1], sufG[i + 1]);
            l = lcm(preL[i - 1], sufL[i + 1]);
        }

        if (g * l > ans)
            ans = g * l;
    }

    free(preG);
    free(sufG);
    free(preL);
    free(sufL);

    return ans;
}