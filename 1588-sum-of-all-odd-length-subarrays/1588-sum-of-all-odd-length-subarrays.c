int sumOddLengthSubarrays(int* arr, int arrSize) {
    int ans = 0;

    for (int i = 0; i < arrSize; i++) {
        int left = i + 1;
        int right = arrSize - i;
        int total = left * right;
        int count = (total + 1) / 2;

        ans += arr[i] * count;
    }

    return ans;
}