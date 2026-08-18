int longestSubarray(int* nums, int numsSize)
{
    if (numsSize == 1)
        return 1;

    int* left = (int*)malloc(numsSize * sizeof(int));
    int* right = (int*)malloc(numsSize * sizeof(int));

    int answer = 1;

    // Longest non-decreasing subarray ending at i
    left[0] = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] >= nums[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;

        if (left[i] > answer)
            answer = left[i];
    }

    // Longest non-decreasing subarray starting at i
    right[numsSize - 1] = 1;

    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (nums[i] <= nums[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    // Replace nums[i]
    for (int i = 0; i < numsSize; i++)
    {
        int current = 1;

        if (i > 0)
            current = left[i - 1] + 1;

        if (i < numsSize - 1)
        {
            if (i > 0 && nums[i - 1] <= nums[i + 1])
            {
                current = left[i - 1] + right[i + 1] + 1;
            }
            else
            {
                int rightOnly = right[i + 1] + 1;

                if (rightOnly > current)
                    current = rightOnly;
            }
        }

        if (current > answer)
            answer = current;
    }

    free(left);
    free(right);

    return answer;
}