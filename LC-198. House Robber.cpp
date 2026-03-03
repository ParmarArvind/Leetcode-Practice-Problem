class Solution {
public:
    /*
    int dp[101];
    ✅ Characteristics:
    DP array is fixed size (101)
    It is declared as a class member (global inside class)
    Memory is allocated at compile time (static memory)
    You reset it using:
    memset(dp,-1,sizeof(dp));
⚠️ Limitation:
    */
    int dp[101];
    int solve(vector<int> &nums,int i)
    {
        if(i >= nums.size()) return 0;

        // use stored result
        if(dp[i] != -1) return dp[i];

        int steal=nums[i]+solve(nums,i+2);
        int skip=solve(nums,i+1);
        return dp[i]= max(steal,skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};



//  metod -2 
/*
vector<int> dp(nums.size()+1, -1);
DP size depends on input
Allocated dynamically at runtime
Passed as reference to recursive function
Works for any input size
  */
class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i >= nums.size()) return 0;

        // use stored result
        if(dp[i] != -1) return dp[i];

        int steal=nums[i]+solve(nums,i+2,dp);
        int skip=solve(nums,i+1,dp);
        return dp[i]= max(steal,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums,0,dp);
    }
};


//  method -3 bottom up
// reducce memory used by recusion (stack)
class Solution { 
public:
    int rob(vector<int>& nums) {

        int prevPrev=0;
        int prev=nums[0];
        

        for(int i=2;i<=nums.size();i++)
        {
            int steal=nums[i-1]+prevPrev;
            int skip=prev;
            
            prevPrev=prev;
            prev= max(steal, skip);
            
        }

        return prev;
    }
};
