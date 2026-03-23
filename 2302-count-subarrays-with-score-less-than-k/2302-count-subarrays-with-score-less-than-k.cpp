class Solution {
public:
    long long atMost(vector<int>& nums, long long k) {
        int i = 0;
        long long sum = 0, ans = 0;

        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        return atMost(nums, k);
    }
};