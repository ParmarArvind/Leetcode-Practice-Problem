class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        int n = s.length();
        // Initialize 2D vector with empty char '\0' as placeholder
        vector<vector<char>> temp(numRows, vector<char>(n, '\0'));

        int i = 0;
        int col = 0;

        while (i < n) {
            // Downward fill: fill each row in the current column
            for (int row = 0; row < numRows && i < n; row++) {
                temp[row][col] = s[i++];
            }

            // Upward diagonal fill: fill rows from numRows-2 to 1 in next columns
            for (int row = numRows - 2; row >= 1 && i < n; row--) {
                col++;
                temp[row][col] = s[i++];
            }
            col++; // Move to next column after diagonal fill
        }

        // Collect result by row-major traversal skipping placeholder chars
        string result;
        for (int row = 0; row < numRows; row++) {
            for (int c = 0; c <= col; c++) {
                if (temp[row][c] != '\0') {
                    result.push_back(temp[row][c]);
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> ans(numRows, "");
        int i = 0;
        int n = s.length();

        while (i < n) {
            // Downward fill
            for (int index = 0; index < numRows && i < n; index++) {
                ans[index] += s[i++];
            }
            // Diagonal upward fill
            for (int index = numRows - 2; index >= 1 && i < n; index--) {
                ans[index] += s[i++];
            }
        }

        string res = "";
        for (const string& str : ans) {
            res += str;
        }
        return res;
    }
};
