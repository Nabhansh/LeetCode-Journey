class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10);
        for (int x : digits)
            freq[x]++;

        vector<int> ans;

        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 8; k += 2) {
                    if (freq[i] > 0) {
                        freq[i]--;

                        if (freq[j] > 0) {
                            freq[j]--;

                            if (freq[k] > 0)
                                ans.push_back(i * 100 + j * 10 + k);

                            freq[j]++;
                        }

                        freq[i]++;
                    }
                }
            }
        }

        return ans;
    }
};