class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i]) !=st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};
