class Solution {
public:
    vector<int> memo;
    bool solve(int pos ,vector<int>& nums ){
        if (pos >= nums.size() - 1) return true;     // reached last index
        if (memo[pos] != -1) return memo[pos];       // already solved

        int maxJump = min((int)nums.size() - 1, pos + nums[pos]);
        for (int next = pos + 1; next <= maxJump; next++) {
            if (solve(next, nums)) {
                return memo[pos] = 1;   // path found
            }
        }
        return memo[pos] = 0;           // no path
    }
    
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), -1);   // initialize memo
        return solve(0, nums);    // start from index 0
    }
};