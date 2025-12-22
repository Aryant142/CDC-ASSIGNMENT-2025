class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> res;
    int freq = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && nums[i] == nums[i - 1]) {
            freq++;
        } else {
            if (freq > n / 3)
                res.push_back(nums[i - 1]);
            freq = 1;
        }
    }

    return res;
}

};