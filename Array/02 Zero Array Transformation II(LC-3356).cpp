class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries,int k)
    {
        int n=nums.size();
        int q=queries.size();
        vector<int>diff(n,0);

        for(int i=0;i<=k;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];

            diff[start] +=val;
            if(end+1 <n) diff[end+1] -=val;
        }

        for(int i=1;i<n;i++)
        {
            diff[i] =diff[i]+diff[i-1];
            if(nums[i-1]>diff[i-1]) return false;
        }

        if(nums[n-1]> diff[n-1]) return false;

        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        
        // bool isZero=true;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]!=0) {
        //         isZero=false;
        //         break;
        //     }
        // }
        // if(isZero) return 0;

        auto lambda = [](int x) {
            return x == 0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)) return 0; // no need to process any query

        for(int i=0;i<q;i++)
        {
            if(check(nums,queries,i)) return i+1;
        }
        return -1;
    }
};


class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries,int k)
    {
        int n=nums.size();
        int q=queries.size();
        vector<int>diff(n,0);

        for(int i=0;i<=k;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];

            diff[start] +=val;
            if(end+1 <n) diff[end+1] -=val;
        }

        for(int i=1;i<n;i++)
        {
            diff[i] =diff[i]+diff[i-1];
            if(nums[i-1]>diff[i-1]) return false;
        }

        if(nums[n-1]> diff[n-1]) return false;

        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();

        auto lambda = [](int x) {
            return x == 0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)) return 0; // no need to process any query

        int start=0;
        int end=q-1;
        int result=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(check(nums,queries,mid)) {
                result=mid+1;
                end=mid-1;
            }
            else start=mid+1;
        }
        return result;
    }
};
