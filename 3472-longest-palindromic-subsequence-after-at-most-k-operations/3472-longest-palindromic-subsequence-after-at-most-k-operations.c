#include <stdlib.h>
#include <string.h>

#define MAXN 205
#define MAXK 205

int memo[MAXN][MAXN][MAXK];
char str[MAXN];
int n;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int solve(int l, int r, int k)
{
    if (l > r)
        return 0;

    if (l == r)
        return 1;

    if (memo[l][r][k] != -1)
        return memo[l][r][k];

    int ans = 0;

    /* Skip left */
    ans = max(ans, solve(l + 1, r, k));

    /* Skip right */
    ans = max(ans, solve(l, r - 1, k));

    /* Match both */
    int diff = abs(str[l] - str[r]);
    int cost = diff;

    if (26 - diff < cost)
        cost = 26 - diff;

    if (cost <= k)
    {
        ans = max(ans,
                  2 + solve(l + 1, r - 1, k - cost));
    }

    memo[l][r][k] = ans;
    return ans;
}

int longestPalindromicSubsequence(char *s, int K)
{
    strcpy(str, s);
    n = strlen(s);

    memset(memo, -1, sizeof(memo));

    return solve(0, n - 1, K);
}