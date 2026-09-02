class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0];
        int longest = logs[0][1];
        int prev = logs[0][1];
        
        for (int i = 1; i < logs.size(); i++) {
            int time = logs[i][1] - prev;
            
            if (time > longest || (time == longest && logs[i][0] < ans)) {
                longest = time;
                ans = logs[i][0];
            }
            
            prev = logs[i][1];
        }
        
        return ans;
    }
};