int minimumLevels(int* possible, int possibleSize) {
    int total = 0;

    // Calculate total score
    for (int i = 0; i < possibleSize; i++) {
        total += (possible[i] == 1) ? 1 : -1;
    }

    int aliceScore = 0;

    // Alice must complete at least 1 level,
    // and Bob must also have at least 1 level.
    for (int i = 0; i < possibleSize - 1; i++) {
        aliceScore += (possible[i] == 1) ? 1 : -1;

        int bobScore = total - aliceScore;

        if (aliceScore > bobScore) {
            return i + 1;
        }
    }

    return -1;
}