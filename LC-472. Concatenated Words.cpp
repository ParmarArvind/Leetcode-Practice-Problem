class Solution {
public:
    unordered_map<string,bool> mp;
    bool isConcatenated(string &word,unordered_set<string> &st)
    {
        if(mp.find(word)!= mp.end()) return mp[word];
       int m=word.size();
       for(int i=0;i<m;i++)
       {
            string prefix=word.substr(0,i+1);
            string suffix=word.substr(i+1);

            if(st.find(prefix) != st.end() && ( st.find(suffix)!=st.end() || isConcatenated(suffix,st) ) )
            {
                return mp[word]=true;
            }
       }
       return mp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st;

        for(string & word:words)
        {
            st.insert(word);
        }

        vector<string> result;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(isConcatenated(words[i],st)) result.push_back(words[i]);
        }

        return result;
        
        
    }
};
