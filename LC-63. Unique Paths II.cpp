
class Solution {
public:
    int dp[101][101];
    int n ,m;
    int solve(vector<vector<int>>& obstacleGrid,int row,int col)
    {
        if(row>=m || col >=n) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==m-1 && col==n-1) return 1;

        if(dp[row][col] !=-1 ) return dp[row][col];

        int right = solve(obstacleGrid, row, col + 1);
        int down  = solve(obstacleGrid, row + 1, col);

        return dp[row][col] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(obstacleGrid,0,0);
    }
};
