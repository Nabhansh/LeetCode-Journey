class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = count(text.begin(), text.end(), ' ');

        vector<string> words;
        stringstream ss(text);
        string word;

        while (ss >> word)
            words.push_back(word);

        if (words.size() == 1)
            return words[0] + string(spaces, ' ');

        int gap = spaces / (words.size() - 1);
        int extra = spaces % (words.size() - 1);

        string ans;

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];

            if (i < words.size() - 1)
                ans += string(gap, ' ');
        }

        ans += string(extra, ' ');
        return ans;
    }
};