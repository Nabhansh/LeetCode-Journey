int minOperations(char* s) {
    int n = strlen(s);

    // Already sorted
    int sorted = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted)
        return 0;

    // Cannot sort a length-2 string because
    // the entire string cannot be selected.
    if (n == 2)
        return -1;

    char mn = s[0];
    char mx = s[0];

    for (int i = 1; i < n; i++) {
        if (s[i] < mn)
            mn = s[i];
        if (s[i] > mx)
            mx = s[i];
    }

    // One operation is enough
    if (s[0] == mn || s[n - 1] == mx)
        return 1;

    // Minimum or maximum is somewhere in the middle
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == mn || s[i] == mx)
            return 2;
    }

    return 3;
}