class Solution {
public:
    int sd(vector<int>& nums, int k) {
        if (k == 0)
            return 0;

        unordered_map<int, int> mp;
        int r = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[r]]--;
                if (mp[nums[r]] == 0)
                    mp.erase(nums[r]);
                r++;
            }

            ans += (j - r + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = sd(nums,k);
        int ans2 = sd(nums,k-1);

        int result = ans1-ans2;
        return result;
    }
};
