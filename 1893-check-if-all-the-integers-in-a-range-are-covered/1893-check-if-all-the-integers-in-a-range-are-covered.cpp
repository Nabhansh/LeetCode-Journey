class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> covered(52, 0);

        for (auto &r : ranges) {
            for (int i = r[0]; i <= r[1]; i++)
                covered[i] = 1;
        }

        for (int i = left; i <= right; i++) {
            if (!covered[i])
                return false;
        }

        return true;
    }
};