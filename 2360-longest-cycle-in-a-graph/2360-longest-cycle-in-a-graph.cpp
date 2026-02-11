class Solution {
public:
    vector<int> vis, depth;
    int ans = -1;

    void dfs(int node, vector<int>& edges, int d) {
        vis[node] = 1;
        depth[node] = d;

        int next = edges[node];

        if (next != -1) {
            if (vis[next] == 0) {
                dfs(next, edges, d + 1);
            }
            else if (vis[next] == 1) {
                // Found cycle
                ans = max(ans, d - depth[next] + 1);
            }
        }

        vis[node] = 2;  // mark as finished
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vis.assign(n, 0);
        depth.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, edges, 0);
            }
        }

        return ans;
    }
};
