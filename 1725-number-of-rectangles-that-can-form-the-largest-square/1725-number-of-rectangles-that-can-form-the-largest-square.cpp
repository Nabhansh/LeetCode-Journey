class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int mx = 0;
        int ans = 0;

        for (auto& r : rectangles) {
            int side = min(r[0], r[1]);

            if (side > mx) {
                mx = side;
                ans = 1;
            } else if (side == mx) {
                ans++;
            }
        }

        return ans;
    }
};