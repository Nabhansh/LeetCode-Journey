class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> mp;

        for (string& s : words) {
            vector<int> diff;
            for (int i = 1; i < s.size(); i++)
                diff.push_back(s[i] - s[i - 1]);

            mp[diff].push_back(s);
        }

        for (auto& [key, val] : mp) {
            if (val.size() == 1)
                return val[0];
        }

        return "";
    }
};