int maxBalancedShipments(int *weight, int weightSize) {
    int answer = 0;
    int currentMaximum = 0;

    for (int i = 0; i < weightSize; ++i) {
        if (weight[i] > currentMaximum)
            currentMaximum = weight[i];

        if (weight[i] < currentMaximum) {
            ++answer;
            currentMaximum = 0;
        }
    }

    return answer;
}