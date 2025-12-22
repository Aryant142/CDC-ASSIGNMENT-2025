class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            // Check if mid is a peak
            if (nums[mid] > nums[mid + 1]) {
                // If mid is greater than its next element, the peak must be on the left half
                end = mid;
            } else {
                // If mid is smaller than its next element, the peak must be on the right half
                start = mid + 1;
            }
        }
        
        // When start == end, we have found the peak
        return start;
    }
};