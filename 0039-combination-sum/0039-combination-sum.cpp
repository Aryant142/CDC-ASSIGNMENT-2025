class Solution {
public:
    void combination(int idx, vector<int>& arr, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0 || idx >= arr.size()) return;

        // Include current element
        temp.push_back(arr[idx]);
        combination(idx, arr, target - arr[idx], temp, ans); // stay on same idx
        temp.pop_back();

        // Exclude current element
        combination(idx + 1, arr, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // sort to ensure combinations are in order
        vector<vector<int>> ans;
        vector<int> temp;
        combination(0, arr, target, temp, ans);
        return ans;
    }
};

