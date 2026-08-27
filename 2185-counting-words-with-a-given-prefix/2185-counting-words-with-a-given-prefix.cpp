class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for (string& word : words) {
            if (word.size() >= pref.size() &&
                word.compare(0, pref.size(), pref) == 0)
                ans++;
        }

        return ans;
    }
};