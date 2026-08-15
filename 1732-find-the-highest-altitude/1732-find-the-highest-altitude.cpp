class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0;
        int highest = 0;

        for (int x : gain) {
            current += x;
            highest = max(highest, current);
        }

        return highest;
    }
};