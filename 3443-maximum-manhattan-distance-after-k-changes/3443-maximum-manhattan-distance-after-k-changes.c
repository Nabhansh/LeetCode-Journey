int maxDistance(char* s, int k) {
    int ans = 0;

    const char dir[4][2] = {
        {'N', 'E'},
        {'N', 'W'},
        {'S', 'E'},
        {'S', 'W'}
    };

    for (int d = 0; d < 4; d++) {
        int pos = 0;
        int used = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == dir[d][0] || s[i] == dir[d][1]) {
                pos++;
            } else if (used < k) {
                pos++;
                used++;
            } else {
                pos--;
            }

            if (pos > ans)
                ans = pos;
        }
    }

    return ans;
}