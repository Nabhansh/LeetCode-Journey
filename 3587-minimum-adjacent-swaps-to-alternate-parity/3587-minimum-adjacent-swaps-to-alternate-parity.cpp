class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int even = 0, odd = 0;

        for (int x : nums) {
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        // Impossible to alternate
        if (abs(even - odd) > 1)
            return -1;

        long long evenCost = 0;
        long long oddCost = 0;

        int evenIndex = 0;
        int oddIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                // Even numbers should occupy 0, 2, 4, ...
                int target = evenIndex * 2;
                evenCost += abs(i - target);
                evenIndex++;
            } else {
                // Odd numbers should occupy 0, 2, 4, ...
                int target = oddIndex * 2;
                oddCost += abs(i - target);
                oddIndex++;
            }
        }

        // More evens -> pattern must start with even
        if (even > odd)
            return evenCost;

        // More odds -> pattern must start with odd
        if (odd > even)
            return oddCost;

        // Equal numbers -> either pattern works
        return min(evenCost, oddCost);
    }
};
