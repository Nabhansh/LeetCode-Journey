int maxActiveSectionsAfterTrade(char* s) {
    int n = strlen(s);
    int ones = 0, gain = 0, prevZero = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;   // 掃出一個 run
        int len = j - i;
        if (s[i] == '1') {
            ones += len;
            // 這段 1 的「前一個 run 是 0」且「後面還有 run（必為 0）」→ 被 0 包圍
            if (prevZero > 0 && j < n) {
                int k = j;
                while (k < n && s[k] == '0') k++;  // 右側 0 區塊長度
                int g = prevZero + (k - j);
                if (g > gain) gain = g;
            }
            prevZero = 0;
        } else {
            prevZero = len;   // 記錄這段 0 的長度，供下一段 1 使用
        }
        i = j;
    }
    return ones + gain;
}