class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;

        for (int i = 1; i <= n; i++)
            cnt[digitSum(i)]++;

        int mx = 0;

        for (auto &p : cnt)
            mx = max(mx, p.second);

        int ans = 0;

        for (auto &p : cnt) {
            if (p.second == mx)
                ans++;
        }

        return ans;
    }
};