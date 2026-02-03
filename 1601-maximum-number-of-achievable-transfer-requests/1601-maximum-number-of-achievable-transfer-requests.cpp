class Solution {
public:
    int ans = 0;

    void dfs(int idx, vector<vector<int>>& req, vector<int>& balance, int count) {
        // All requests processed
        if (idx == req.size()) {
            for (int x : balance) {
                if (x != 0) return;  // not balanced
            }
            ans = max(ans, count);
            return;
        }

        // Option 1: Take this request
        int from = req[idx][0];
        int to   = req[idx][1];

        balance[from]--;
        balance[to]++;
        dfs(idx + 1, req, balance, count + 1);

        // Backtrack
        balance[from]++;
        balance[to]--;

        // Option 2: Skip this request
        dfs(idx + 1, req, balance, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> balance(n, 0);
        dfs(0, requests, balance, 0);
        return ans;
    }
};
