class Solution {
public:
    int ans = INT_MAX;

    void dfs(int idx, vector<int>& cookies, vector<int>& child) {
        // All bags assigned
        if (idx == cookies.size()) {
            int unfair = *max_element(child.begin(), child.end());
            ans = min(ans, unfair);
            return;
        }

        for (int i = 0; i < child.size(); i++) {
            child[i] += cookies[idx];
            dfs(idx + 1, cookies, child);
            child[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.rbegin(), cookies.rend());  // big bags first
        vector<int> child(k, 0);
        dfs(0, cookies, child);
        return ans;
    }
};
