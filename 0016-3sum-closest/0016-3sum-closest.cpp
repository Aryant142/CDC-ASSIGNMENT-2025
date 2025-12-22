class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2]; // start with the first three

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (abs(target - currentSum) < abs(target - closest)) {
                    closest = currentSum; // update closest if this is nearer
                }

                if (currentSum < target) {
                    j++;
                } else if (currentSum > target) {
                    k--;
                } else {
                    return target; // perfect match
                }
            }
        }

        return closest;
    }
};
