typedef long long ll;

long long findMaximumScore(int* nums, int numsSize) {
    ll ans = 0;
    int mx = nums[0];

    for (int i = 1; i < numsSize; i++) {
        ans += mx;
        if (nums[i] > mx)
            mx = nums[i];
    }

    return ans;
}