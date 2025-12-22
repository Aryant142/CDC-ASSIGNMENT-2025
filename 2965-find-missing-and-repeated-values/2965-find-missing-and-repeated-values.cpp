class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int repeated, missing;
        int actualsum = 0, expectedsum = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualsum += val;

                if (s.find(val) != s.end()) {
                    repeated = val; // Found duplicate
                } else {
                    s.insert(val);
                }
            }
        }

        int total = n * n;
        expectedsum = (total * (total + 1)) / 2;
        missing = expectedsum - actualsum + repeated;

        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }
};
