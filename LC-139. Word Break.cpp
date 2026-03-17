class Solution {
public:
    unordered_set<string>st;
    int dp[301];
    int n;
    bool solve(int i,string &s)
    {
        if(i>=n) return true; // we reached at last index so string a succesfully breaked.

        if(st.find(s) !=st.end()) return true;
        if(dp[i] !=-1 ) return dp[i];

        for(int l=1;l<=n;l++)
        {
            if(st.find(s.substr(i,l)) !=st.end() && solve(i+l,s)) return dp[i]= true;
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto &word: wordDict)
        {
            st.insert(word);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};
