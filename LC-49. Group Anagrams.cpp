class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        int n=strs.size();
        for(int i=0; i<n;i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }

        vector<vector<string>> result;
        for(auto &it:mp)
        {
            vector<string> temp;
            for(int i=0;i<it.second.size();i++)
            {
                int idx=it.second[i];
                temp.push_back(strs[idx]);
            }
            result.push_back(temp);
        }

        return result;
    }
};
