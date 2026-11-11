class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a';
        int row = coordinates[1] - '0';

        return (col + row) % 2 == 0;
    }
};