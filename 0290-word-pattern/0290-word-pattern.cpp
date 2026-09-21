class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word)
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];

            if (mp.count(c) && mp[c] != words[i])
                return false;

            if (rev.count(words[i]) && rev[words[i]] != c)
                return false;

            mp[c] = words[i];
            rev[words[i]] = c;
        }

        return true;
    }
};