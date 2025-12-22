class Solution {
public:
    int mySqrt(int n) {
        int start = 0;
        int end = n;
        long long ans = -1;
        
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            
            if (mid * mid == n) {
                return mid;
            } else if (mid * mid < n) { // mid is small, move right
                ans = mid;
                start = mid + 1;
            } else { // mid*mid > n, move left
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
