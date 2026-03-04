// TLE 
class Solution {
public:

    int solve(int i, bool canBuy, vector<int>& prices)
    {
        if(i == prices.size())
            return 0;

        int profit = 0;

        if(canBuy)
        {
            int buy = -prices[i] + solve(i+1, false, prices);
            int skip = solve(i+1, true, prices);

            profit = max(buy, skip);
        }
        else
        {
            int sell = prices[i] + solve(i+1, true, prices);
            int skip = solve(i+1, false, prices);

            profit = max(sell, skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(false,1,prices);
    }
};

// memozation 
class Solution {
public:
    int dp[30001][2];
    int solve(int i, int canBuy, vector<int>& prices)
    {
        if(i == prices.size())
            return 0;
        

        if(dp[i][canBuy] !=-1) return dp[i][canBuy];
        int profit = 0;

        if(canBuy)
        {
            int buy = -prices[i] + solve(i+1, false, prices);
            int skip = solve(i+1, true, prices);

            profit = max(buy, skip);
        }
        else
        {
            int sell = prices[i] + solve(i+1, true, prices);
            int skip = solve(i+1, false, prices);

            profit = max(sell, skip);
        }

        return dp[i][canBuy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(false,1,prices);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
            {
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};
