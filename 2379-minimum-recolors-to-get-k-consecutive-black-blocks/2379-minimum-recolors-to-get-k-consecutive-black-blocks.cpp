class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        int ans = INT_MAX;

        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W')
                white++;

            if (i >= k && blocks[i - k] == 'W')
                white--;

            if (i >= k - 1)
                ans = min(ans, white);
        }

        return ans;
    }
};