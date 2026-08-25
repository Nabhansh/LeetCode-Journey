class Solution {
public:
    int countPoints(string rings) {
        vector<set<char>> rods(10);

        for (int i = 0; i < rings.size(); i += 2)
            rods[rings[i + 1] - '0'].insert(rings[i]);

        int ans = 0;

        for (auto &s : rods)
            if (s.size() == 3)
                ans++;

        return ans;
    }
};