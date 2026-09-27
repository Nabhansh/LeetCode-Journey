class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int x = num;

        while (x) {
            mask = (mask << 1) | 1;
            x >>= 1;
        }

        return num ^ mask;
    }
};