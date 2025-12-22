class Solution {
public:
    // Function to check if it's safe to place a queen at (row, col)
    bool issafe(int col, int n, int row, vector<string>& board) {
        // Check the entire row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // Check the entire column
        for (int x = 0; x < n; x++) {
            if (board[x][col] == 'Q') return false;
        }

        // Check top-left diagonal (↖)
        for (int a = row, b = col; a >= 0 && b >= 0; a--, b--) {
            if (board[a][b] == 'Q') return false;
        }

        // Check top-right diagonal (↗)
        for (int a = row, b = col; a >= 0 && b < n; a--, b++) {
            if (board[a][b] == 'Q') return false;
        }

        return true; // No attacks → safe
    }

    // Recursive function to solve N-Queens
    void nqueens(vector<vector<string>>& ans, int n, int row,
                 vector<string>& board) {

        // Base case: all queens placed
        if (row == n) { 
            ans.push_back({board});
            return;
        }

        // Try placing queen in each column of current row
        for (int i = 0; i < n; i++) {
            if (issafe(i, n, row, board)) {
                board[row][i] = 'Q';             // Place queen
                nqueens(ans, n, row + 1, board); // Recurse for next row
                board[row][i] = '.';             // Backtrack
            }
        }
    }

    // Main function to start solving
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // Empty board
        vector<vector<string>> ans;              // Store all solutions
        nqueens(ans, n, 0, board);               // Start from row 0
        return ans;
    }
};
