class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x ^= nums[i];
        }
        int flip = 0;
        while (x != 0 || k != 0) {
            if ((x & 1) != (k & 1))
                flip++;
            x >>= 1;
            k >>= 1;
        }
        return flip;
    }
};