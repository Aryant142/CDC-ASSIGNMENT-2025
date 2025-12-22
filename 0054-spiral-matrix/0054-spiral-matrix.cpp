class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        if (mat.empty()) return res;

        int n = mat.size();
        int m = mat[0].size();

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            // 1. Left to Right
            for (int i = left; i <= right; i++)
                res.push_back(mat[top][i]);
            top++;

            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++)
                res.push_back(mat[i][right]);
            right--;

            // 3. Right to Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    res.push_back(mat[bottom][i]);
                bottom--;
            }

            // 4. Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    res.push_back(mat[i][left]);
                left++;
            }
        }

        return res;
    }
};
