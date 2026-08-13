class Solution {
public:
    bool canFormArray(vector<int>& arr,
                      vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>*> pieceByFirst;

        for (auto& piece : pieces)
            pieceByFirst[piece[0]] = &piece;

        int index = 0;

        while (index < arr.size()) {
            if (!pieceByFirst.count(arr[index]))
                return false;

            vector<int>& piece = *pieceByFirst[arr[index]];

            for (int value : piece) {
                if (index >= arr.size() ||
                    arr[index] != value) {
                    return false;
                }

                ++index;
            }
        }

        return true;
    }
};