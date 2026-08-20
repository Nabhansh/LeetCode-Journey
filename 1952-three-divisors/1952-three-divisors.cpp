class Solution {
public:
    bool isThree(int n) {
        int root = sqrt(n);
        return root * root == n && isPrime(root);
    }
    
    bool isPrime(int n) {
        if (n < 2)
            return false;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        
        return true;
    }
};