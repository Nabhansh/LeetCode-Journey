#define MAX_N 100005

typedef struct {
    int l, r, c;
} Segment;

long long prefix[MAX_N]; 

int cmp(const void* a, const void* b) {
    Segment* segA = (Segment*)a;
    Segment* segB = (Segment*)b;
    if (segA->l < segB->l) {
        return -1;
    } else if (segA->l > segB->l) {
        return 1;
    }
    return 0;
}

int findLeft(Segment* coins, int n, int val) {
    int low = 0, high = n - 1, mid, result = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (coins[mid].l <= val && coins[mid].r >= val) {
            return mid;
        } else if (coins[mid].l > val) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

bool isSatisfied(Segment* coins, int n, long long val, int k) {
    long long sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        int r = coins[i].r;
        if (r - k < 0) {
            if (prefix[i] > sum) {
                sum = prefix[i];
            }
            continue;
        }
        int idx = findLeft(coins, n, r - k);
        if (idx == n || coins[idx].l > r - k) {
            long long tempSum = prefix[i];
            if (idx > 0) {
                tempSum -= prefix[idx - 1];
            }
            if (tempSum > sum) {
                sum = tempSum;
            }
        } else {
            long long tempSum = prefix[i] - prefix[idx];
            tempSum += (coins[idx].r - (r - k)) * 1LL * coins[idx].c;
            if (tempSum > sum) {
                sum = tempSum;
            }
        }
    }

    if (sum >= val) {
        return true;
    }

    sum = 0;

    for (i = 0; i < n; i++) {
        int r = coins[i].l;
        int idx = findLeft(coins, n, r + k);
        if (idx == n) {
            long long tempSum = prefix[n - 1];
            if (i > 0) {
                tempSum -= prefix[i - 1];
            }
            if (tempSum > sum) {
                sum = tempSum;
            }
            continue;
        }
        if (coins[idx].l > r + k) {
            long long tempSum = prefix[idx - 1];
            if (i > 0) {
                tempSum -= prefix[i - 1];
            }
            if (tempSum > sum) {
                sum = tempSum;
            }
        } else {
            long long tempSum = prefix[idx];
            if (i > 0) {
                tempSum -= prefix[i - 1];
            }
            tempSum -= (coins[idx].r - (r + k) + 1) * 1LL * coins[idx].c;
            if (tempSum > sum) {
                sum = tempSum;
            }
        }
    }

    return sum >= val;
}

long long maximumCoins(int** coins, int coinsSize, int* coinsColSize, int k) {
    Segment* segCoins = (Segment*)malloc(coinsSize * sizeof(Segment));

    for (int i = 0; i < coinsSize; i++) {
        segCoins[i].l = coins[i][0];
        segCoins[i].r = coins[i][1];
        segCoins[i].c = coins[i][2];
    }

    qsort(segCoins, coinsSize, sizeof(Segment), cmp);

    prefix[0] = (segCoins[0].r - segCoins[0].l + 1) * 1LL * segCoins[0].c;
    for (int i = 1; i < coinsSize; i++) {
        prefix[i] = prefix[i - 1] + (segCoins[i].r - segCoins[i].l + 1) * 1LL * segCoins[i].c;
    }

    long long low = 1, high = 1e12, ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isSatisfied(segCoins, coinsSize, mid, k)) {
            if (mid > ans) {
                ans = mid;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    free(segCoins);
    return ans;
}