
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if (grid[0][0] == 1) 
        return 0;  
        if (grid[m-1][n-1] == 1) 
        return 0; 

        vector<long long> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[j] = 0;    
                } else {
                    if (j > 0) dp[j] += dp[j-1];  
                }
            }
        }
        return dp[n-1];
    }
};
