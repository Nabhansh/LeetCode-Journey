int isPrime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int maximumPrimeDifference(int* nums, int numsSize) {
    int first = -1;
    int last = -1;

    for (int i = 0; i < numsSize; i++) {
        if (isPrime(nums[i])) {
            if (first == -1) {
                first = i;
            }

            last = i;
        }
    }

    return last - first;
}