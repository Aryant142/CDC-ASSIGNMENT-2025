class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    // Binary search to find next non-overlapping job
    int findNext(int endTime) {
        int l = 0, r = jobs.size() - 1;
        int ans = jobs.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (jobs[mid][0] >= endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(int i) {
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Skip
        int skip = solve(i + 1);

        // Take
        int nextIndex = findNext(jobs[i][1]);
        int take = jobs[i][2] + solve(nextIndex);

        return dp[i] = max(skip, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());  // sort by start time
        dp.resize(n, -1);

        return solve(0);
    }
};
