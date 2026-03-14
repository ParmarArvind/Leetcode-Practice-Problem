class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=magazine.size();
        int m=ransomNote.size();
        if(m>n) return false;

        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[ magazine[i]-'a' ]++;
        }

        for(int i=0;i<m;i++)
        {
            if(freq[ransomNote[i]-'a']==0 ) return false;
            
            freq[ransomNote[i]-'a']--;
        }

        return true;
    }
};
