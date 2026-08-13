class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> answer(n, 0);

        if (k == 0)
            return answer;

        int left, right;

        if (k > 0) {
            left = 1;
            right = k;
        } else {
            left = n + k;
            right = n - 1;
        }

        int windowSum = 0;

        for (int i = left; i <= right; ++i)
            windowSum += code[i % n];

        for (int i = 0; i < n; ++i) {
            answer[i] = windowSum;

            windowSum -= code[left % n];
            ++left;
            ++right;
            windowSum += code[right % n];
        }

        return answer;
    }
};