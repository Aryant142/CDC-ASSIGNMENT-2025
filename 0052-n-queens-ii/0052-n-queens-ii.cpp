class Solution {
public:
    bool Safe(vector<string>& board, int row, int col, int n) {
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void Queens(vector<string>& board, int row, int n,
                vector<vector<string>>& ans, int& count) {

        if (row == n) {
            count++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (Safe(board, row, j, n)) {
                board[row][j] = 'Q';
                Queens(board, row + 1, n, ans, count);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        int count = 0;
        Queens(board, 0, n, ans, count);
        return count;
    }
};
