class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        int maxe = *max_element(begin(nums),end(nums));
       
        long long r = 0, j = 0, ans = 0 , countmax=0;

        while(j < n){
            if(nums[j] == maxe){
                countmax++;
            }

            while(countmax >= k ){
                ans += n-j;

                if(nums[r] == maxe){
                    countmax--;
                }
                r++;
            }
            j++;
        }
        return ans;
    }
};