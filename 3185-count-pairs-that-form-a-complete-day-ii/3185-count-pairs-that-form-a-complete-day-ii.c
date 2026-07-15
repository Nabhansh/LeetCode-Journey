long long countCompleteDayPairs(int* hours, int hoursSize) {
    long long count[24] = {0};
    long long ans = 0;

    for (int i = 0; i < hoursSize; i++) {
        int rem = hours[i] % 24;
        int need = (24 - rem) % 24;

        ans += count[need];
        count[rem]++;
    }

    return ans;
}