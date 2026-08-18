int minLengthAfterRemovals(char* s)
{
    int a = 0;
    int b = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a')
            a++;
        else
            b++;
    }

    return abs(a - b);
}