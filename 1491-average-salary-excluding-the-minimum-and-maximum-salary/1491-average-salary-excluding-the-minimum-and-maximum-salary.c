double average(
    int* salary,
    int salarySize
)
{
    int minimum = salary[0];
    int maximum = salary[0];

    long long sum = 0;

    for (int i = 0; i < salarySize; i++)
    {
        if (salary[i] < minimum)
            minimum = salary[i];

        if (salary[i] > maximum)
            maximum = salary[i];

        sum += salary[i];
    }

    sum -= minimum;
    sum -= maximum;

    return (double)sum / (salarySize - 2);
}