class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();       // rows
        int m = mat[0].size();    // columns

        // Initialize result matrix with size m x n
        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[j][i] = mat[i][j]; // Transpose logic
            }
        }

        return result;
    }
};
