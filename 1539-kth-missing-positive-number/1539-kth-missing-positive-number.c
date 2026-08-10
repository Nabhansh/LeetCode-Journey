int findKthPositive(int* arr, int arrSize, int k)
{
    int current = 1;

    for (int i = 0; i < arrSize; i++)
    {
        while (current < arr[i])
        {
            k--;

            if (k == 0)
                return current;

            current++;
        }

        current++;
    }

    while (k > 0)
    {
        k--;

        if (k == 0)
            return current;

        current++;
    }

    return current;
}