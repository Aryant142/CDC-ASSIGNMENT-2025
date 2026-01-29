class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& jd, int n, int d, int idx) {
        // Base case: last day takes all remaining jobs
        if (d == 1) {
            int maxd = jd[idx];
            for (int i = idx; i < n; i++)
                maxd = max(maxd, jd[i]);
            return maxd;
        }

        if (dp[idx][d] != -1) return dp[idx][d];

        int maxd = 0;
        int result = INT_MAX;

        // Ensure enough jobs remain for remaining days
        for (int i = idx; i <= n - d; i++) {
            maxd = max(maxd, jd[i]);  // max of current day
            int next = solve(jd, n, d - 1, i + 1);
            result = min(result, maxd + next);
        }

        return dp[idx][d] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        dp.resize(n, vector<int>(d + 1, -1));
        return solve(jobDifficulty, n, d, 0);
    }
};
