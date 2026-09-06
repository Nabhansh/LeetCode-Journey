int minPenalty(int period, int* lights, int lightsSize, int* arrivalTime, int arrivalTimeSize) {
    int maxGreen = 0;

    for (int i = 0; i < lightsSize; i++) {
        if (lights[i] > maxGreen)
            maxGreen = lights[i];
    }

    int ans = 0;

    for (int i = 0; i < arrivalTimeSize; i++) {
        int r = arrivalTime[i] % period;

        if (r >= maxGreen) {
            int wait = period - r;
            if (wait > ans)
                ans = wait;
        }
    }

    return ans;
}