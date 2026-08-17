class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int column = coordinates[0] - 'a' + 1;
        int row = coordinates[1] - '0';

        return (row + column) % 2 == 1;
    }
};