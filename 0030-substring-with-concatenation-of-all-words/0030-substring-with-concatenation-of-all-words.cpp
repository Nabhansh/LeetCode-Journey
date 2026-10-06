class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int len = words[0].size();
        int total = len * words.size();

        if (s.size() < total) return ans;

        unordered_map<string, int> need;

        for (auto &w : words)
            need[w]++;

        for (int start = 0; start < len; start++) {
            int left = start;
            int count = 0;
            unordered_map<string, int> have;

            for (int right = start; right + len <= s.size(); right += len) {
                string word = s.substr(right, len);

                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                have[word]++;
                count++;

                while (have[word] > need[word]) {
                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }

                if (count == words.size()) {
                    ans.push_back(left);

                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};