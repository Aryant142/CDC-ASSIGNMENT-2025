#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
               // Remove all smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add current element index
            dq.push_back(i);
            
            // Remove indices out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            
            // Window starts from index k-1
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};
