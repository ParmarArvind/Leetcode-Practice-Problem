class Solution {
public:
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(),bank.end());
        unordered_set<string > visited;

        queue<string> que;
        que.push(startGene);
        visited.insert(startGene);
        int level=0;
        
        while(!que.empty())
        {
            int n=que.size();
            while(n--)
            {
                string curr=que.front();
                que.pop();
                if(curr==endGene) return level;

                for(char ch:"ACGT")
                {
                    for(int i=0;i<8;i++)
                    {
                        string ngbr=curr;
                        ngbr[i]=ch;
                        if(bankSet.find(ngbr) != bankSet.end() && visited.find(ngbr)==visited.end() )
                        {
                            visited.insert(ngbr);
                            que.push(ngbr);
                        }
                    }
                }
            }
            level++;
        }

    return -1;
    }
};
