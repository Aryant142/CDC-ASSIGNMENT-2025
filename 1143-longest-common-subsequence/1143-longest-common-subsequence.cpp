class Solution {
public:
    
    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j) {

        // Base case
        if (i >= s1.length() || j >= s2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(dp, s1, s2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(
                solve(dp, s1, s2, i, j + 1),
                solve(dp, s1, s2, i + 1, j)
            );
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(dp, s1, s2, 0, 0);
    }
};
