class Solution {
public:
// using map
    int candy(vector<int>& rating) {
        vector<pair<int,int>> mp;
        int n=rating.size();
        vector<int>candy(n,1);
        for(int i=0;i<n;i++)
        {
            mp.push_back({i,rating[i]});
        }
        auto lambda=[](auto &a,auto &b)
        {
            return a.second<b.second;
        };
        sort(mp.begin(),mp.end(),lambda);

        for(auto &p:mp)
        {
            int i=p.first;
            int ele=p.second;
            if(i>0 && i< n-1) 
            {
                if(rating[i-1]<rating[i] && rating[i+1]<rating[i])
                {
                    candy[i]=max(candy[i-1],candy[i+1]) +1;
                
                }
                else if(rating[i+1]<rating[i]){
                    candy[i]=candy[i+1]+1;
                }
                else if(rating[i-1]<rating[i]){
                    candy[i]=candy[i-1]+1;
                }
            }
            else if(i>0) 
            {
                if(rating[i-1]<rating[i])
                {
                    candy[i]=candy[i-1]+1;
                }
            }else if(i<n-1) 
            {
                if(rating[i+1]<rating[i])
                {
                    candy[i]=candy[i+1]+1;
                }
            }
        }
        int  result=accumulate(candy.begin(),candy.end(),0);
        return result;
    }
};
