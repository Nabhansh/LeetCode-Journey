class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0;
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        for (int x : salary) {
            total += x;
            minimum = min(minimum, x);
            maximum = max(maximum, x);
        }

        return (double)(total - minimum - maximum)
               / (salary.size() - 2);
    }
};