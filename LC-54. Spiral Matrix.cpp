class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int top=0, left=0;
        int bottom= row-1 , right=col-1;
        
        vector<int>ans;

        while(top<=bottom && left<=right)
        {
            // print top row; here i is fixed =top;
            for(int j=left ; j<=right;j++) 
            {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // print right column; here j is fixed =right;
            for(int i=top ; i<=bottom;i++) 
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // print bottom row; here i is fixed =bootm;
            if(top>bottom) break;
            for(int j=right ; j>=left;j--) 
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;

            // print right column; here j is fixed =left;
            if(left>right) break;
            for(int i=bottom ; i>=top;i--) 
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return ans;
    }
};
