class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;

        for (auto& piece : pieces)
            mp[piece[0]] = piece;

        int i = 0;

        while (i < arr.size()) {
            if (!mp.count(arr[i]))
                return false;

            vector<int>& piece = mp[arr[i]];

            for (int x : piece) {
                if (i >= arr.size() || arr[i] != x)
                    return false;

                i++;
            }
        }

        return true;
    }
};