char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed) {
    int maxTime = releaseTimes[0];
    char ans = keysPressed[0];

    for (int i = 1; i < releaseTimesSize; i++) {
        int duration = releaseTimes[i] - releaseTimes[i - 1];

        if (duration > maxTime ||
            (duration == maxTime && keysPressed[i] > ans)) {
            maxTime = duration;
            ans = keysPressed[i];
        }
    }

    return ans;
}