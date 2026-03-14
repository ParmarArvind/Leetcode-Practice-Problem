class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        
        unordered_map<char, string>mp;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss >> word)
        {
            if( i !=n )
            {
                if(mp.find(pattern[i]) !=mp.end() ){
                    if( mp[pattern[i]] != word) return false;
                }
                else mp[pattern[i]]= word;
            }
            else return false;

            i++;
        }
        if(i!=n) return false;

        unordered_map<string, char>mp2;
        stringstream ss2(s);
        
        i=0;
        while(ss2 >> word)
        {
            if( i !=n )
            {
                if(mp2.find(word) !=mp2.end() ){
                    if( mp2[word] != pattern[i]) return false;
                }
                else mp2[word]= pattern[i];
            }
             else return false;
             i++;
        }
        if(i!=n) return false;

        return true;

    }
};
