class Solution {
public:
    int solve(long long curr, long long next, int n) {
        int count = 0;
        while (curr <= n) {
            count += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1;

        while (k > 0) {
            int count = solve(curr, curr + 1, n);
            if (count <= k) {
                curr++;
                k -= count;  
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
