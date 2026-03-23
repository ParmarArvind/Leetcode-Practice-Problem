// method -1 rec+memo
class Solution {
public:
    int dp[201][201];
    int n;
    int m;
    int solve(vector<vector<int>>& grid,int row,int col)
    {
        if(row>=m || col >=n) return INT_MAX;
        
        if(row==m-1 && col==n-1) return grid[row][col];

        if(dp[row][col] !=-1 ) return dp[row][col];

        int sameCol=solve(grid,row,col+1);
        int nextCol=solve(grid,row+1,col);

        return dp[row][col]=grid[row][col] + min(sameCol,nextCol);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 201; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(grid,0,0);
    }
};

//method -2  recu +memo but better
class Solution {
public:
    int t[201][201];
    int m,n;
    int solve(vector<vector<int>>& grid ,int i,int j )
    {
        if(i==m-1 && j==n-1) return grid[i][j];

        if(t[i][j] != INT_MAX) return t[i][j];

        // move left , if we are at the last row
        if(i==m-1 ) return t[i][j]= grid[i][j] +solve(grid,i,j+1);

        // move bottom,  if we are at the last column
        if(j==n-1) return t[i][j]=grid[i][j] + solve(grid,i+1,j);

        return t[i][j]= grid[i][j] + min(solve(grid,i+1,j) , solve(grid,i,j+1)) ;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        // memset(t,INT_MAX,sizeof(t));  // we can't use it for INT_MAX 

        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
            {
                t[i][j]=INT_MAX;
            }
        }

        return solve(grid ,0,0);
    }
};


// method -3 bottom up 
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int t[m+1][n+1];
         //t[i][j] = minVal to reach from (0, 0) to (i, j)
        t[0][0]=grid[0][0];

        //filling the first row
        for(int i=1;i<m;i++)
        {
            t[i][0]=t[i-1][0]+grid[i][0];
        }

        //filling the first col
        for(int j=1;j<n;j++)
        {
            t[0][j]=t[0][j-1] +grid[0][j];
        }

        for(int i=1; i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                t[i][j]=grid[i][j]+min(t[i-1][j] , t[i][j-1]);
            }
        }

        return t[m-1][n-1];
    }
};
