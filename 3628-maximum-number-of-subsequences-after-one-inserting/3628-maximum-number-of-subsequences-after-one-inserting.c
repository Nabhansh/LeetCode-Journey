long long numOfSubsequences(char *s) {
    long long remainingT = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == 'T')
            ++remainingT;
    }

    long long countL = 0;
    long long countC = 0;

    long long lct = 0;
    long long lc = 0;
    long long ct = 0;
    long long bestInsertedC = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        char ch = s[i];

        if (ch == 'T') {
            --remainingT;
            ct += countC;
        }

        if (ch == 'C') {
            lct += countL * remainingT;
            lc += countL;
            ++countC;
        }

        if (ch == 'L')
            ++countL;

        long long gain = countL * remainingT;

        if (gain > bestInsertedC)
            bestInsertedC = gain;
    }

    long long bestGain = lc; /* Insert T at the end. */

    if (ct > bestGain)       /* Insert L at the beginning. */
        bestGain = ct;

    if (bestInsertedC > bestGain)
        bestGain = bestInsertedC;

    return lct + bestGain;
}