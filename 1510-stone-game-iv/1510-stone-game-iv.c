bool winnerSquareGame(int n)
{
    bool dp[n + 1];

    // dp[i] = true  -> current player can win with i stones
    // dp[i] = false -> current player will lose with i stones

    dp[0] = false;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = false;

        // Try removing every perfect square <= i
        for (int j = 1; j * j <= i; j++)
        {
            int square = j * j;

            // If removing this square leaves the opponent
            // in a losing position, current player wins.
            if (dp[i - square] == false)
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}