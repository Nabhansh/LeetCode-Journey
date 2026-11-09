class Solution {
public:
    int countMatches(vector<vector<string>>& items,
                     string ruleKey, string ruleValue) {
        int index = 0;

        if (ruleKey == "color")
            index = 1;
        else if (ruleKey == "name")
            index = 2;

        int ans = 0;

        for (auto& item : items) {
            if (item[index] == ruleValue)
                ans++;
        }

        return ans;
    }
};