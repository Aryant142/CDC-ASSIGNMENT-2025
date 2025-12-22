class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // 1. Left to Right
            for (int i = left; i <= right; i++)
                mat[top][i] = num++;
            top++;

            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++)
                mat[i][right] = num++;
            right--;

            // 3. Right to Left
            for (int i = right; i >= left; i--)
                mat[bottom][i] = num++;
            bottom--;

            // 4. Bottom to Top
            for (int i = bottom; i >= top; i--)
                mat[i][left] = num++;
            left++;
        }

        return mat;
    }
};
