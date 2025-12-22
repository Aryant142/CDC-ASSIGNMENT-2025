class Solution {
public:
    void combination(vector<int>& arr, int target, int indx,
                     vector<vector<int>>& ans, vector<int>& combine) {

        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        if (indx >= arr.size() || target < 0)
            return;

        // Include current element
        combine.push_back(arr[indx]);
        combination(arr, target - arr[indx], indx + 1, ans, combine);
        combine.pop_back();

        // Skip all duplicates of current element before moving to the next
        int nextIndex = indx + 1;
        while (nextIndex < arr.size() && arr[nextIndex] == arr[indx])
            nextIndex++;

        // Exclude current element and move to next non-duplicate
        combination(arr, target, nextIndex, ans, combine);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> combine;
        combination(arr, target, 0, ans, combine);
        return ans;
    }
};
