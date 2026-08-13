class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1,
                              vector<string>& word2) {
        int array1 = 0;
        int array2 = 0;
        int index1 = 0;
        int index2 = 0;

        while (array1 < word1.size() &&
               array2 < word2.size()) {
            if (word1[array1][index1] !=
                word2[array2][index2]) {
                return false;
            }

            ++index1;
            ++index2;

            if (index1 == word1[array1].size()) {
                ++array1;
                index1 = 0;
            }

            if (index2 == word2[array2].size()) {
                ++array2;
                index2 = 0;
            }
        }

        return array1 == word1.size() &&
               array2 == word2.size();
    }
};