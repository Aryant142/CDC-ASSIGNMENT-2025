class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // 1-indexed graph
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st; // {distance, node}

        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {
            auto it = *(st.begin());
            int d = it.first;
            int u = it.second;
            st.erase(it);

            for (auto &nbr : adj[u]) {
                int v = nbr.first;
                int wt = nbr.second;

                if (d + wt < dist[v]) {
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }

                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
