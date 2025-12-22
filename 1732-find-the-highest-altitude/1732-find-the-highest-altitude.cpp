class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ps(n + 1, 0);  // Include starting altitude (0)

        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + gain[i];
        }

        int maxi = 0;
        for (auto& i : ps) {
            maxi = max(maxi, i);
        }

        return maxi;
    }
};
