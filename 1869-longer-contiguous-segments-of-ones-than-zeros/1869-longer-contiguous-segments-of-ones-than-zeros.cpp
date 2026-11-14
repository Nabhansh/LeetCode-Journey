class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        int maxOnes = 0, maxZeros = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
                zeros = 0;
            } else {
                zeros++;
                ones = 0;
            }

            maxOnes = max(maxOnes, ones);
            maxZeros = max(maxZeros, zeros);
        }

        return maxOnes > maxZeros;
    }
};