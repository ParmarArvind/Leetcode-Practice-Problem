//brute force
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero=0;
        int product =1;
        int n=nums.size();
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                countZero++;
                idx=i;
                continue;
            }
            product *= nums[i];
        }

        vector<int>result(n,0);
        if(countZero>1) return result;
         if(countZero==1)
         {
            result[idx]=product;
            return result;
         } 

         for(int i=0;i<n;i++)
         {
            result[i]=product/nums[i];
         }

         return result;
    }
};

//method -2 As per requirement
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>pre(n,1);
        vector<int>suff(n,1);
        vector<int>ans(n);

        //nums = { 1 ,2 ,3 ,4}

        for(int i=1;i<n;i++)
        {
            pre[i] =pre[i-1]*nums[i-1];
        }
        // pre={ 1,1,2,6}

        for(int i=n-2;i>=0;i--)
        {
            suff[i] =suff[i+1]*nums[i+1];
        }
        // suff = {24,12,4,1 }

        for(int i=0;i<n;i++)
        {
            ans[i]=pre[i]*suff[i];
        }       
        return ans;

    }
};
