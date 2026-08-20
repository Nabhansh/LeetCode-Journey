class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        
        for (char c : s) {
            int x = c - 'a' + 1;
            sum += x / 10 + x % 10;
        }
        
        for (int i = 1; i < k; i++) {
            int x = 0;
            
            while (sum > 0) {
                x += sum % 10;
                sum /= 10;
            }
            
            sum = x;
        }
        
        return sum;
    }
};