int countValidSubarrays(int* nums, int numsSize, int x) {
    int ans = 0;

    for (int l = 0; l < numsSize; l++) {
        long long sum = 0;

        for (int r = l; r < numsSize; r++) {
            sum += nums[r];

            long long t = sum;
            while (t >= 10)
                t /= 10;

            if (sum % 10 == x && t == x)
                ans++;
        }
    }

    return ans;
}