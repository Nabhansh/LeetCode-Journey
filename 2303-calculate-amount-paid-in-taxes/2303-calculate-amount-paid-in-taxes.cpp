class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int prev = 0;

        for (auto& b : brackets) {
            int upper = b[0];
            int percent = b[1];

            int amount = min(income, upper) - prev;
            if (amount > 0)
                ans += amount * percent / 100.0;

            prev = upper;

            if (income <= upper)
                break;
        }

        return ans;
    }
};