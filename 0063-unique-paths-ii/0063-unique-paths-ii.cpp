class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        vector<vector<int>> dp (obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        return paths(obstacleGrid , dp ,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
        
    }

    int paths(vector<vector<int>>& grid ,vector<vector<int>> & dp , int i , int j){
 if(i<0 ||j<0||grid[i][j] == 1){
            return 0;
        }

        if( i==0 && j==0){
            return 1;
        }
       

        if(dp[i][j]!=0){
            return dp[i][j];
        }

        int u = paths(grid,dp,i-1,j);
        int l = paths(grid,dp,i,j-1);

        return dp[i][j] =  u + l;
    }
};