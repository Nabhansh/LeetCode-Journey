class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26] = {};
        int n = words.size();

        for (string& word : words) {
            for (char c : word) {
                freq[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0)
                return false;
        }

        return true;
    }
};