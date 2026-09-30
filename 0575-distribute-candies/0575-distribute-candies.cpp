class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min((int)s.size(), (int)candyType.size() / 2);
    }
};