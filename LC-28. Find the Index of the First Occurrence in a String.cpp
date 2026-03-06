//Using Brute Force -1
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        for(int i=0; i<haystack.size();i++)
        {
            int k=i;
            int j=0;
            while(haystack[k]==needle[j])
            {
                k++;
                j++;
                if(j+1>needle.size()) return i;
                if(k>haystack.size()) return -1;
            }
            
        }
        return -1;
    }
};

 //Using Brute Force -2 (same)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        for(int i = 0; i <= m-n; i++) 
        { //haystack
            for(int j = 0; j < n; j++) 
            { //needle
                if(haystack[i+j] != needle[j])
                    break;
                
                if(j == n-1) // haystack[i+j] == needle[j]
                    return i;
            }
        }
        
        return -1;
    }
};
