int numIdenticalPairs(int* nums, int numsSize)
{
    int count[101] = {0};
    int pairs = 0;

    for (int i = 0; i < numsSize; i++)
    {
        pairs += count[nums[i]];
        count[nums[i]]++;
    }

    return pairs;
}