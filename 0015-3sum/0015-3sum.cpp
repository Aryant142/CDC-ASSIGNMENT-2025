class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        sort(n.begin(), n.end());  // Sort the array first
        vector<vector<int>> ans;
        int ni = n.size();

        for (int i = 0; i < ni - 2; i++) {
            if (i > 0 && n[i] == n[i - 1]) continue; // skip duplicates for i

            int j = i + 1;
            int k = ni - 1;

            while (j < k) {
                int sum = n[i] + n[j] + n[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    ans.push_back({n[i], n[j], n[k]});
                    j++;
                    k--;

                    // skip duplicates for j and k
                    while (j < k && n[j] == n[j - 1]) j++;
                    while (j < k && n[k] == n[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};
