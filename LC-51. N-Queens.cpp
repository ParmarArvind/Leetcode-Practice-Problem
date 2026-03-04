// O(n!) T.C.      O(n) by recursion
class Solution {
public:
     vector<vector<string>> result;
     int N;

     bool isSafe(vector<string> &board ,int row,int col)
     {
        // check for col
        for(int i=row;i>=0;i--)
        {
            if(board[i][col] =='Q')
            {
                return false;
            }
        }

        // check for upward right diagonal
        for(int i=row,j=col ;i>=0  && j<N ; i--, j++)
        {
            if(board[i][j] =='Q')
            {
                return false;
            }
        }

        // check for upward left diagonal
        for(int i=row,j=col ;i>=0 && j>=0 ; i--, j--)
        {
            if(board[i][j] =='Q')
            {
                return false;
            }
        }

        return true;
     }

    void solve(vector<string> &board ,int row)
    {
        if(row>=N)
        {
            result.push_back(board);
            return ;
        }

        for(int col=0;col<N;col++)
        {
            if(isSafe(board,row,col))
            {
                board[row][col]='Q';
                solve(board, row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string>board(n,string(n,'.')); // [{...}, {...}, {...}]
        solve(board,0);
    
    return result;
    }
};


//  method -1 imoroving isSafe function 
class Solution {
public:
    vector<vector<string>> result;
    int N;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;

    void solve(vector<string> &board ,int row)
    {
        if(row>=N)
        {
            result.push_back(board);
            return ;
        }

        for(int col=0;col<N;col++)
        {
            int diag_id       = row-col;
            int anti_diag_id  = row+col;
            
            /*
                If the col, or diagonal or anti_diaonal
                are used, means one of them has a Queen placed
                already which can attack, so look for other column
            */
            if(cols.find(col) != cols.end() ||
              diags.find(diag_id) != diags.end() ||
              antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;
            
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            
            solve(board, row+1);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string>board(n,string(n,'.')); // [{...}, {...}, {...}]
        solve(board,0);
    
    return result;
    }
};
