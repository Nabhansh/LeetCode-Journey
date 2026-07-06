int binaryGap(int n) {
    int last = -1;
    int ans = 0;
    int pos = 0;

    while (n) {
        if (n & 1) {
            if (last != -1 && pos - last > ans)
                ans = pos - last;
            last = pos;
        }
        pos++;
        n >>= 1;
    }

    return ans;
}