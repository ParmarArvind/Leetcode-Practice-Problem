class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        
        int left=0;
        int right=0;
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R') right++;
            else left++;

            if(left==right) result++;
        }
        
        return result;
    }
};
