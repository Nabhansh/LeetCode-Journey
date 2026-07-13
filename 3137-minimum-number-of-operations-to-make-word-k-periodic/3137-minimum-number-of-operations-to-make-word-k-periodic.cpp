class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int>m;
        
        int n = word.length();
        for(int i=0;i<=n-k;i++)
        {
            if(i%k==0)
            {
                string sub = word.substr(i, k);
                m[sub]++;
            }
        }
        
        int max_occ = 0;
        for(auto it:m)
        {
            if(it.second>max_occ)
            {
                max_occ = it.second;
            }
        }
        
        int rem = n - k*max_occ;
        
        return rem/k;
    }
};