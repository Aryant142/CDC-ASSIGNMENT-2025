#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());              // group duplicates
        vector<vector<int>> ans;
        permuteRec(nums, 0, ans);
        return ans;
    }

private:
    void permuteRec(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int j = index; j < nums.size(); ++j) {
            if (used.count(nums[j])) 
                continue;                            // skip duplicate value at this position
            used.insert(nums[j]);

            swap(nums[index], nums[j]);
            permuteRec(nums, index + 1, ans);
            swap(nums[index], nums[j]);            // backtrack
        }
    }
};
