class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int years[101] = {};

        for (auto& log : logs) {
            years[log[0] - 1950]++;
            years[log[1] - 1950]--;
        }

        int cur = 0;
        int best = 0;
        int year = 1950;

        for (int i = 0; i < 101; i++) {
            cur += years[i];

            if (cur > best) {
                best = cur;
                year = 1950 + i;
            }
        }

        return year;
    }
};