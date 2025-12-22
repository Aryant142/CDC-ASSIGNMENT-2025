class Solution {
public:
    int searchInsert(vector<int>& num, int target) {
        int n = num.size();
        int start = 0;   // Initialize start index
        int end = n - 1; // Initialize end index
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2; // Calculate mid index

            if (num[mid] == target) { // Check if the middle element is the target
                return mid;            // Return the index if found
            } else if (num[mid] < target) { // If target is greater, ignore left half
                start = mid + 1;
            } else { // If target is smaller, ignore right half
                end = mid - 1;
            }
        }
        
        // Return the position where the target would be inserted
        return start;
    }
};
