class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=target-nums[i];
            int start=i+1;
            int end=n-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==x) return {i+1,mid+1};
                else if(nums[mid]<x) start=mid+1;
                else end=mid-1;
            }
        }
        return {1,2};
    }
};
