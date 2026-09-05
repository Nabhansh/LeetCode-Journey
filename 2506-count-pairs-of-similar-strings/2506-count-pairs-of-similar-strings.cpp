class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            int a = 0;

            for (char c : words[i])
                a |= 1 << (c - 'a');

            for (int j = 0; j < i; j++) {
                int b = 0;

                for (char c : words[j])
                    b |= 1 << (c - 'a');

                if (a == b)
                    ans++;
            }
        }

        return ans;
    }
};