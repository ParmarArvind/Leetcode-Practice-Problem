class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());


        int n=nums.size();
        if(n<=1) return n; 
        
        int count=1;
        int result=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] ==0 ) continue;
            else if(nums[i]-nums[i-1] ==1 ) count++;
            else count=1; 
             result=max(result,count);
        }
        return result;

    }
};
