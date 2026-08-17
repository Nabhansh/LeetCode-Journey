class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> numbers;

        int n = word.size();

        for (int i = 0; i < n; ) {
            if (isdigit(word[i])) {
                string num = "";

                while (i < n && isdigit(word[i])) {
                    num += word[i];
                    i++;
                }

                int j = 0;

                while (j < num.size() && num[j] == '0') {
                    j++;
                }

                if (j == num.size()) {
                    num = "0";
                }
                else {
                    num = num.substr(j);
                }

                numbers.insert(num);
            }
            else {
                i++;
            }
        }

        return numbers.size();
    }
};