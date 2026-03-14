class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.size() < words.size()*words[0].size()) return {};

        unordered_map<string,int> mp;

        for(auto &w : words)
            mp[w]++;

        int n = s.size();
        int m = words[0].size();
        int total = words.size();

        vector<int> result;

        for(int start = 0; start < m; start++)
        {
            unordered_map<string,int> visited;
            int count = 0;

            int i = start;
            int j = start;

            while(j + m <= n)
            {
                string sub = s.substr(j,m);
                j += m;

                if(mp.find(sub) != mp.end())
                {
                    visited[sub]++;
                    count++;

                    while(visited[sub] > mp[sub])
                    {
                        string left = s.substr(i,m);
                        visited[left]--;
                        count--;
                        i += m;
                    }

                    if(count == total)
                    {
                        result.push_back(i);

                        string left = s.substr(i,m);
                        visited[left]--;
                        count--;
                        i += m;
                    }
                }
                else
                {
                    visited.clear();
                    count = 0;
                    i = j;
                }
            }
        }

        return result;
    }
};
