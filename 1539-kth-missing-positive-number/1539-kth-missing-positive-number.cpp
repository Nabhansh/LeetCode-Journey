class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int current = 1;
        int i = 0;

        while (k > 0) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                k--;
                if (k == 0)
                    return current;
            }

            current++;
        }

        return current - 1;
    }
};