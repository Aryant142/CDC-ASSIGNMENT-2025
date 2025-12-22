class Solution {
public:
    vector<int> searchRange(vector<int>& num, int target) {
        int n = num.size();
        int start = 0 ; // Initialize start index
        int end = n - 1;    // Initialize end index
        vector<int> ans(2,-1);
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index

            if (num[mid] == target) { // Check if the middle element is the target
                ans[0]=mid;       // Update ans if a larger element is found
                end = mid - 1;   // Continue searching in the left half

            } else if (num[mid] < target) { // If target is greater, ignore left half
                start = mid + 1;
            } else { // If target is smaller, ignore right half
                end = mid - 1;
            }
        }
        
       start = 0 ; // Initialize start index
     end = n - 1;    // Initialize end index

        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index

            if (num[mid] == target) { // Check if the middle element is the target
                ans[1]=mid;       // Update ans if a larger element is found
                start = mid + 1;   // Continue searching in the left half

            } else if (num[mid] < target) { // If target is greater, ignore left half
                start = mid + 1;
            } else { // If target is smaller, ignore right half
                end = mid - 1;
            }
        }
        return ans;
    }
};