class Solution {
public:
    vector<int> parent, rank1;

    int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (rank1[a] < rank1[b]) parent[a] = b;
        else if (rank1[a] > rank1[b]) parent[b] = a;
        else {
            parent[b] = a;
            rank1[a]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<vector<int>> edges;

        // 🔥 Create all edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        // Sort by weight
        sort(edges.begin(), edges.end());

        parent.resize(n);
        rank1.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int cost = 0;

        // Kruskal
        for (auto &e : edges) {
            int w = e[0];
            int u = e[1];
            int v = e[2];

            if (findParent(u) != findParent(v)) {
                cost += w;
                unionSet(u, v);
            }
        }

        return cost;
    }
};
