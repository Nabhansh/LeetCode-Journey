class Solution {
public:
    int getValue(string s) {
        int value = 0;

        for (char c : s) {
            value = value * 10 + (c - 'a');
        }

        return value;
    }

    bool isSumEqual(string firstWord, string secondWord,
                    string targetWord) {
        int a = getValue(firstWord);
        int b = getValue(secondWord);
        int c = getValue(targetWord);

        return a + b == c;
    }
};