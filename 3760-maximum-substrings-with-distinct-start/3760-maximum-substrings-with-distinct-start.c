int maxDistinct(char* s)
{
    int seen[26] = {0};
    int ans = 0;

    for (int i = 0; s[i]; i++)
    {
        int x = s[i] - 'a';

        if (!seen[x])
        {
            seen[x] = 1;
            ans++;
        }
    }

    return ans;
}