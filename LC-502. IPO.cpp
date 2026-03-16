class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minPQ;
        priority_queue<pair<int,int>> maxPQ;

        int n = capital.size();

        for(int i=0;i<n;i++)
        {
            minPQ.push({capital[i], profits[i]});
        }

        while(k--)
        {
            // move all affordable projects
            while(!minPQ.empty() && w >= minPQ.top().first)
            {
                maxPQ.push({minPQ.top().second, minPQ.top().first});
                minPQ.pop();
            }

            if(maxPQ.empty())
                break;

            w += maxPQ.top().first;
            maxPQ.pop();
        }

        return w;
    }
};


class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int,int>>vec;

        priority_queue<int>maxProfit;

        int n = capital.size();

        for(int i=0;i<n;i++)
        {
            vec.push_back({capital[i], profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(k--)
        {
            // move all affordable projects
            while(i<n && w >= vec[i].first)
            {
                maxProfit.push(vec[i].second);
                i++;
            }

            if(maxProfit.empty())
                break;

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
