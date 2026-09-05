class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int last = -1;

        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] == 0)
                continue;

            if (last != -1 && forts[i] != forts[last])
                ans = max(ans, i - last - 1);

            last = i;
        }

        return ans;
    }
};