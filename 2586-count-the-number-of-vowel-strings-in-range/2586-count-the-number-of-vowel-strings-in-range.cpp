class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;

        for (int i = left; i <= right; i++) {
            char a = words[i].front();
            char b = words[i].back();

            bool first = a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
            bool last = b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';

            if (first && last)
                ans++;
        }

        return ans;
    }
};