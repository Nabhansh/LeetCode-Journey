int minOperations(char* s)
{
    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int moves = (26 - (s[i] - 'a')) % 26;

        if (moves > ans)
            ans = moves;
    }

    return ans;
}