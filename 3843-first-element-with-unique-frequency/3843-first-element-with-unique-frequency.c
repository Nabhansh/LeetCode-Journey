int firstUniqueFreq(int* nums, int numsSize) {
    int cnt[100001] = {0};
    int freq[100001] = {0};

    for (int i = 0; i < numsSize; i++)
        cnt[nums[i]]++;

    for (int i = 1; i <= 100000; i++)
        if (cnt[i] > 0)
            freq[cnt[i]]++;

    for (int i = 0; i < numsSize; i++)
        if (freq[cnt[nums[i]]] == 1)
            return nums[i];

    return -1;
}