long long countArrays(int *original,
                      int originalSize,
                      int **bounds,
                      int boundsSize,
                      int *boundsColSize)
{
    long long left = -4000000000000000000LL;
    long long right = 4000000000000000000LL;

    for (int i = 0; i < originalSize; i++)
    {
        long long diff = (long long)original[i] - original[0];

        long long L = (long long)bounds[i][0] - diff;
        long long R = (long long)bounds[i][1] - diff;

        if (L > left)
            left = L;

        if (R < right)
            right = R;
    }

    if (left > right)
        return 0;

    return right - left + 1;
}