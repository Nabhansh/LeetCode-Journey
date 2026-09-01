class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] != -1) {
                if (i - first[x] - 1 != distance[x])
                    return false;
            } else {
                first[x] = i;
            }
        }

        return true;
    }
};