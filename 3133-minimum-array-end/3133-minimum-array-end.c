long long minEnd(int n, int x) {
    long long ans = x;
    long long remaining = (long long)n - 1;
    long long bit = 1;

    while (remaining > 0) {
        if ((ans & bit) == 0) {
            if (remaining & 1) {
                ans |= bit;
            }

            remaining >>= 1;
        }

        bit <<= 1;
    }

    return ans;
}