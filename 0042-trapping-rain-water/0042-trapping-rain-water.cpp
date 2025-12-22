
 class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0; // important edge case

        vector<int> rm(n), lm(n);
        int ans = 0;
        
        rm[0] = h[0];
        lm[n-1] = h[n-1];

        for (int i = 1; i < n; i++) {
            rm[i] = max(rm[i-1], h[i]);
        }

        for (int k = n-2; k >= 0; k--) { // fixed condition
            lm[k] = max(lm[k+1], h[k]);
        }

        for (int j = 0; j < n; j++) {
            ans += min(rm[j], lm[j]) - h[j];
        }
        
        return ans;
    }
};
