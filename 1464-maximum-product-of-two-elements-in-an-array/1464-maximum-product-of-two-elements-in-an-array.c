int maxProduct(int* nums, int numsSize)
{
    int largest = -1;
    int secondLargest = -1;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest)
        {
            secondLargest = nums[i];
        }
    }

    return (largest - 1) * (secondLargest - 1);
}