class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int ans = 0;

        while (ss >> word) {
            bool valid = true;
            int hyphen = 0;

            for (int i = 0; i < word.size(); i++) {
                char c = word[i];

                if (isdigit(c)) {
                    valid = false;
                    break;
                }

                if (c == '-') {
                    hyphen++;

                    if (hyphen > 1 ||
                        i == 0 ||
                        i == word.size() - 1 ||
                        !islower(word[i - 1]) ||
                        !islower(word[i + 1])) {
                        valid = false;
                        break;
                    }
                }

                if (c == '!' || c == '.' || c == ',') {
                    if (i != word.size() - 1) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
                ans++;
        }

        return ans;
    }
};