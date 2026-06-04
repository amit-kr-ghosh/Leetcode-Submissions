class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        int ans = path(grid.size()-1,grid[0].size()-1,grid,dp);
        return ans>=1e9 ? -1 : ans;
    }

    int path(int r , int c  , vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        if(r<0||c<0){
            return 1e9;
        }
        if(r==0 &&c==0){
            return grid[r][c];
        }

        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int top = grid[r][c] + path(r-1,c,grid,dp);
        int left = grid[r][c] + path(r,c-1,grid,dp);

        return dp[r][c] = min(top,left);
    }

};