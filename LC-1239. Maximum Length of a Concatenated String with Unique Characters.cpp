class Solution {
public:
    
    int solve(vector<string>& arr,int idx,int n,string temp)
    {
        vector<bool> freq(26,false);
        bool isDuplicate=false;
        for(auto ch:temp)
        {
            if(freq[ch-'a']==false) freq[ch-'a']=true;
            else isDuplicate=true;
        }

        // base case
        if(idx >= n) 
        {
            if(isDuplicate ==false) return temp.size();
            return 0;
        }

        // store unique char
        
        if(isDuplicate ==false)
        {
            for(int i=0;i<arr[idx].size();i++)
            {
                char ch=arr[idx][i];
                if( freq[ch-'a'] )
                {
                    isDuplicate=true;
                    break;
                }
            }
        }
        
        int take=0;
        if(isDuplicate ==false) take=solve(arr,idx+1,n,temp+arr[idx] );

        int skip=solve(arr,idx+1,n,temp);
        return max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        
        return solve(arr,0,n,"");
    }
};

//  written in easy way 
class Solution {
public:
    bool isDuplicate(string &s1, string &s2)
    {
        int freq[26]={0};
        for(auto ch:s1)
        {
            if(freq[ch-'a'] >0) return true;
            freq[ch-'a']++;
        }

        for(auto ch:s2)
        {
            if(freq[ch-'a'] >0) return true;
            freq[ch-'a']++;
        }
        return false;
    }
    int solve(vector<string>& arr,int idx,int n,string temp)
    {
        // base case
        if(idx >= n)  return temp.size();

        int take=0;
        if(isDuplicate(arr[idx] ,temp) ==false) take=solve(arr,idx+1,n,temp+arr[idx]);

        int skip=solve(arr,idx+1,n,temp);
        return max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        
        return solve(arr,0,n,"");
    }
};
