bool uniformArray(int* nums1, int nums1Size) {
    int minOdd = INT_MAX;

    // Find the smallest odd number
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 1) {
            if (nums1[i] < minOdd) {
                minOdd = nums1[i];
            }
        }
    }

    // No odd numbers -> all are already even
    if (minOdd == INT_MAX)
        return true;

    // If an even number is smaller than
    // the smallest odd, it cannot be converted to odd.
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 0 &&
            nums1[i] < minOdd) {
            return false;
        }
    }

    return true;
}