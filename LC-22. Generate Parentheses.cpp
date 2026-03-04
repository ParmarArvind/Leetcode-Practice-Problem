//Approach-1 (Simple Recursion)
//T.C : O(2n* (2^(2n)) -> Removing constant -> O(n * (2^n))
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    vector<string> result;
    int N;

    bool isValid(string &curr)
    {
        int left = 0;
        for(int i = 0; i < curr.size(); i++)
        {
            if(curr[i] == '(') left++;
            else left--;

            if(left < 0 ) return false;
        }
        return left==0;
    }

    void solve(string& curr)
    {
        if(curr.size() == 2 * N)
        {
            if(isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }
        // DO 
        curr.push_back('(');
        solve(curr);
        // backtrack (undo)
        curr.pop_back();

        
        curr.push_back(')');
        solve(curr);
        curr.pop_back();
       
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";
        solve(curr);
        return result;
    }
};


//T.C : O(2^n)
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr, 0, 0);

        return result;
    }
};
