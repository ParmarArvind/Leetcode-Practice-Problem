
////Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution {
public:
    unordered_map<int,int> freq;
    vector<vector<int>> result;
    int n;

    void solve(vector<int>& temp, vector<int>& nums) {

        if(temp.size() == n) {
            result.push_back(temp);   
            return;
        }
        
        for(auto &it:freq) {
            int num=it.first;
            if(it.second>0) {
                temp.push_back(num);
                freq[num]--;

                solve(temp, nums);

                freq[num]++;
                temp.pop_back();
            }

        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        for(auto num : nums) {
            freq[num]++;
        }

        vector<int> temp;

        solve(temp, nums);

        return result;
    }
};
//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(nPr)

class Solution {
public:
    
    int n;
    void solve(int idx, vector<int>& nums,set<vector<int>>&st) {

        if(idx == n) {
            st.insert(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            
            solve(idx+1, nums,st);
            
            swap(nums[i], nums[idx]);
        }
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        set<vector<int>>st;
        
       solve(0, nums,st);
       vector<vector<int>>result;
       for(auto &vec :st)
       {
            result.push_back(vec);
       }
        return result;
    }
};

//Approach-3 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);

            solve(idx+1, nums);

            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};

