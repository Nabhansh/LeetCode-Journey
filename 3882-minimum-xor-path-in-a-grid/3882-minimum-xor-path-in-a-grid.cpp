class Solution {
public:
    int n , m;

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        const int maxi = 1024;

        vector<vector<vector<bool>>> dp(n , vector<vector<bool>>(m , vector<bool>(maxi , 0)));
        
        dp[0][0][grid[0][0]] = 1;

        for(int i=0 ; i<n ; i++){
            for(int j=0; j<m ; j++){
                for(int x = 0 ; x < maxi ; x++){
                    if(!dp[i][j][x]) continue;

                    if(i+1 < n){
                        dp[i+1][j][x ^ grid[i+1][j]] = 1;
                    }

                    if(j+1 < m){
                        dp[i][j+1][x ^ grid[i][j+1]] = 1;
                    }
                }
            }
        }

        for(int x=0 ; x<maxi ; x++){
            if(dp[n-1][m-1][x]) return x;
        }

        return -1;
    }
};