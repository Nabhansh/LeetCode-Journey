class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string temp = "";
        int ans = 0;

        while (sequence.find(temp + word) != string::npos) {
            temp += word;
            ans++;
        }

        return ans;
    }
};