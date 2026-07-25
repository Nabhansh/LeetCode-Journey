int minCostToMoveChips(int* position, int positionSize) {
    int even = 0, odd = 0;

    for (int i = 0; i < positionSize; i++) {
        if (position[i] & 1)
            odd++;
        else
            even++;
    }

    return even < odd ? even : odd;
}