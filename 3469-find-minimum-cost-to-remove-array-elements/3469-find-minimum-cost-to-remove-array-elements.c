#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define INF 0x3f3f3f3f

int nums[MAXN];
int n;
int dp[MAXN][MAXN];

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int solve(int keep, int next)
{
    if (next >= n)
        return nums[keep];

    if (next == n - 1)
        return max(nums[keep], nums[next]);

    if (dp[keep][next] != -1)
        return dp[keep][next];

    int a = nums[keep];
    int b = nums[next];
    int c = nums[next + 1];

    int ans = INF;

    /* Remove keep & next */
    ans = min(ans,
              max(a, b) + solve(next + 1, next + 2));

    /* Remove keep & next+1 */
    ans = min(ans,
              max(a, c) + solve(next, next + 2));

    /* Remove next & next+1 */
    ans = min(ans,
              max(b, c) + solve(keep, next + 2));

    dp[keep][next] = ans;
    return ans;
}

int minCost(int* arr, int arrSize)
{
    n = arrSize;

    for (int i = 0; i < n; i++)
        nums[i] = arr[i];

    memset(dp, -1, sizeof(dp));

    if (n == 1)
        return nums[0];

    if (n == 2)
        return max(nums[0], nums[1]);

    int ans = INF;

    /* Remove first two */
    ans = min(ans,
              max(nums[0], nums[1]) + solve(2, 3));

    /* Remove first & third */
    ans = min(ans,
              max(nums[0], nums[2]) + solve(1, 3));

    /* Remove second & third */
    ans = min(ans,
              max(nums[1], nums[2]) + solve(0, 3));

    return ans;
}