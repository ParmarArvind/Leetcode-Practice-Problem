//method-1 (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.

class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>st;
    int n;
    
    void solve(vector<int>& nums,vector<int>& temp)
    {
        if(temp.size()==n)
        {
            result.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i])==st.end())
            {
                //do
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,temp);

                // undo
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(nums,temp);

        return result;
    }
};


// method -2  (Swapping elements in nums)
class Solution {
public:
    vector<vector<int>>result;
    int n;
    
    void solve(vector<int>& nums,int idx)
    {
        if(idx==n)
        {
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            //do
            swap(nums[i],nums[idx]);
            solve(nums,idx+1);

            // undo
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        solve(nums,0);

        return result;
    }
};
