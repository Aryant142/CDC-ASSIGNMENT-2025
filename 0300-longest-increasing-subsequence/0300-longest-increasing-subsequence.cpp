class Solution {
public:
    int n;
    vector<vector<int>> dp;  // 2D dp

    int solve(vector<int>& nums, int curr, int pre) {
        if (curr == n) return 0;

        if (dp[curr][pre + 1] != -1)
            return dp[curr][pre + 1];

        int take = 0;

        // handle pre = -1 case
        if (pre == -1 || nums[curr] > nums[pre]) {
            take = 1 + solve(nums, curr + 1, curr);
        }

        int skip = solve(nums, curr + 1, pre);

        return dp[curr][pre + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));  // dp[curr][pre+1]
        return solve(nums, 0, -1);
    }
};
