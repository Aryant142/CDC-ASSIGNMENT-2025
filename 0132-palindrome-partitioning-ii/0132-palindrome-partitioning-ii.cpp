class Solution {
public:
    int n;
    vector<vector<bool>> isPalindrome;
    vector<int> dp;

    void computePalindromeTable(string& s) {
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
    }

    int minCutsFrom(int i, string& s) {
        if (i == n) return -1; // No cut needed after end of string
        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (isPalindrome[i][j]) {
                int cuts = 1 + minCutsFrom(j + 1, s);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i] = minCuts;
    }

    int minCut(string s) {
        n = s.size();
        dp = vector<int>(n, -1);
        computePalindromeTable(s);
        return minCutsFrom(0, s);
    }
};
