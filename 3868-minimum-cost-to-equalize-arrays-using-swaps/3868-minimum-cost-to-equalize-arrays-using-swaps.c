int minCost(int* nums1, int nums1Size,
            int* nums2, int nums2Size) {

    int freq1[80001] = {0};
    int freq2[80001] = {0};

    for (int i = 0; i < nums1Size; i++) {
        freq1[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; i++) {
        freq2[nums2[i]]++;
    }

    int cost = 0;

    for (int x = 1; x <= 80000; x++) {

        // Total frequency must be even
        if ((freq1[x] + freq2[x]) % 2 != 0)
            return -1;

        // Surplus elements in nums1
        int diff = freq1[x] - freq2[x];

        if (diff > 0) {
            cost += diff / 2;
        }
    }

    return cost;
}