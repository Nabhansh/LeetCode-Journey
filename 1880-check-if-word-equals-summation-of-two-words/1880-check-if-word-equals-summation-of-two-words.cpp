class Solution {
public:
    int value(string s) {
        int x = 0;

        for (char c : s)
            x = x * 10 + (c - 'a');

        return x;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return value(firstWord) + value(secondWord) == value(targetWord);
    }
};