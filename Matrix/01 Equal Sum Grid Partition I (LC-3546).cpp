class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                totalSum += (long long)grid[i][j];
            }
        }

        if(totalSum%2==1) return false;
        // check for horizontal cut
        long long upperPartSum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                upperPartSum += (long long)grid[i][j];
            }
            if(upperPartSum == totalSum-upperPartSum) return true;
        }

        // check for vertical cut
        long long leftPartSum=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                leftPartSum += (long long)grid[i][j];
            }
            if(leftPartSum == totalSum-leftPartSum) return true;
        }

        return false;
    }
};
