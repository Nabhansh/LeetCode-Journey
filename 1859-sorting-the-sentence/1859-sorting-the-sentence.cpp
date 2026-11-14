class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;

        vector<string> words(10);

        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();

            words[pos] = word;
        }

        string ans = "";

        for (int i = 1; i < 10; i++) {
            if (words[i].empty())
                break;

            if (!ans.empty())
                ans += " ";

            ans += words[i];
        }

        return ans;
    }
};