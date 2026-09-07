class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;

        int take = min(k, numOnes);
        ans += take;
        k -= take;

        take = min(k, numZeros);
        k -= take;

        take = min(k, numNegOnes);
        ans -= take;

        return ans;
    }
};