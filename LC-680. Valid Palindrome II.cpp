class Solution {
public:
    bool solve(string &s,int start,int end,bool skip)
    {
        if(start>end) return true;
        if(s[start]==s[end] && solve(s,start+1,end-1,skip)) return true;
        else {
            if(skip ) return false;
            skip=true;
            if(solve(s,start+1,end,skip)) return true;
            if(solve(s,start,end-1,skip)) return true;
        } 

        return false;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;

       return solve(s,start,end,false);
    }
};


class Solution {
public:

    bool isPalindrome(string &s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            if(s[i] != s[j])
            {
                // try deleting either left or right character
                return isPalindrome(s, i+1, j) ||
                       isPalindrome(s, i, j-1);
            }

            i++;
            j--;
        }

        return true;
    }
};
