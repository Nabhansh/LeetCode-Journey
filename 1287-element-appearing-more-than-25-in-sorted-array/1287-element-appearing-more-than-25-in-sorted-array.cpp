class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 4;

        for (int i = 0; i + threshold < n; i++) {
            if (arr[i] == arr[i + threshold])
                return arr[i];
        }

        return -1;
    }
};