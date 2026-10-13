class Solution {
public:
    vector<string> findOcurrences(
        string text, string first, string second) {

        stringstream ss(text);
        vector<string> words, result;
        string word;

        while (ss >> word)
            words.push_back(word);

        for (int i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first &&
                words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};