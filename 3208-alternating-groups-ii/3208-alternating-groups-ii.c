int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int count = 0;
    int length = 1;

    for (int i = 1; i < colorsSize + k - 1; i++) {
        int current = colors[i % colorsSize];
        int previous = colors[(i - 1) % colorsSize];

        if (current != previous) {
            length++;
        } else {
            length = 1;
        }

        if (length >= k) {
            count++;
        }
    }

    return count;
}