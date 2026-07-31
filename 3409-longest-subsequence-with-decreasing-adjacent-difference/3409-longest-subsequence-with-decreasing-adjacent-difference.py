class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        U = 301
        n = len(nums)
        g = [[0] * U for _ in range(U)]
        for x in nums:
            f = [0] * U
            f[U - 1] = 1  
            for y in range(1, U):
                d = abs(x - y)
                f[d] = max(f[d], g[y][d] + 1)
            g[x][U - 1] = 1
            for d in range(U - 2, -1, -1):
                g[x][d] = max(g[x][d + 1], f[d])
        ans = 0
        for x in range(1, U):
            ans = max(ans, g[x][0])
        return ans