class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       int n = nums.size();
        map<int,int> mp;
        int r = 0 , j = 0 , ans = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp[nums[j]] > k && r < j){
                mp[nums[r]]--;
                r++;
            }
            ans = max(ans,j-r+1);
            j++ ;
        }
        return ans;
    }
};