class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);

        if (total % 3 != 0)
            return false;

        int target = total / 3;
        int sum = 0;
        int parts = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            sum += arr[i];

            if (sum == target) {
                parts++;
                sum = 0;
            }

            if (parts == 2)
                return true;
        }

        return false;
    }
};