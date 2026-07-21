int maxNumberOfBalloons(char* text) {
    int cnt[26] = {0};

    for (int i = 0; text[i]; i++)
        cnt[text[i] - 'a']++;

    cnt['l' - 'a'] /= 2;
    cnt['o' - 'a'] /= 2;

    int ans = cnt['b' - 'a'];

    if (cnt['a' - 'a'] < ans) ans = cnt['a' - 'a'];
    if (cnt['l' - 'a'] < ans) ans = cnt['l' - 'a'];
    if (cnt['o' - 'a'] < ans) ans = cnt['o' - 'a'];
    if (cnt['n' - 'a'] < ans) ans = cnt['n' - 'a'];

    return ans;
}