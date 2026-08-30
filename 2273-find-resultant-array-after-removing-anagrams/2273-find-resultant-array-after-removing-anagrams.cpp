class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (string& word : words) {
            if (ans.empty()) {
                ans.push_back(word);
            } else {
                string a = ans.back();
                string b = word;
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());

                if (a != b)
                    ans.push_back(word);
            }
        }

        return ans;
    }
};