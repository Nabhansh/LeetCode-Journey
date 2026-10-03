class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;

        for (int i = 0; i < list1.size(); i++)
            mp[list1[i]] = i;

        vector<string> ans;
        int best = INT_MAX;

        for (int i = 0; i < list2.size(); i++) {
            if (mp.count(list2[i])) {
                int sum = i + mp[list2[i]];

                if (sum < best) {
                    best = sum;
                    ans.clear();
                    ans.push_back(list2[i]);
                } else if (sum == best) {
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};