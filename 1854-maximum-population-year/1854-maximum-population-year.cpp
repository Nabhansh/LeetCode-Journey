class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int diff[101] = {};

        for (auto& log : logs) {
            diff[log[0] - 1950]++;
            diff[log[1] - 1950]--;
        }

        int population = 0;
        int maximum = 0;
        int ans = 1950;

        for (int i = 0; i < 100; i++) {
            population += diff[i];

            if (population > maximum) {
                maximum = population;
                ans = 1950 + i;
            }
        }

        return ans;
    }
};