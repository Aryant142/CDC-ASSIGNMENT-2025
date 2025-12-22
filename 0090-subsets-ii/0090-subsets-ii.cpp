class Solution {
public:
    void getsubset(vector<int>& nums,
                   vector<int>& ans,
                   int i,
                   vector<vector<int>>& subset) {
        if (i == nums.size()) {
            subset.push_back(ans);
            return;
        }

        // 1) Include nums[i]
        ans.push_back(nums[i]);
        getsubset(nums, ans, i + 1, subset);

        // 2) Exclude nums[i], then skip duplicates
        ans.pop_back();
        int index = i + 1;
        while (index < nums.size() && nums[index] == nums[index - 1]) {
            index++;
        }
        getsubset(nums, ans, index, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());              // ← make duplicates adjacent
        vector<int> ans;
        vector<vector<int>> subset;
        getsubset(nums, ans, 0, subset);
        return subset;
    }
};