class Solution {
public:
    void getsubset(vector<int>& nums, vector<int>& ans, int i,
                   vector<vector<int>>& subset) {
        if (i == nums.size()) {
            subset.push_back(ans);
            return;
        }

        // Include nums[i]
        ans.push_back(nums[i]);
        getsubset(nums, ans, i + 1, subset);

        // Exclude nums[i]
        ans.pop_back();
        getsubset(nums, ans, i + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> subset;
        getsubset(nums, ans, 0, subset);
        return subset;
    }
};
