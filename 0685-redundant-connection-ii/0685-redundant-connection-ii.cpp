class Solution {
public:
    vector<int> parent, rankArr;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return true;
        if (rankArr[px] < rankArr[py])
            parent[px] = py;
        else if (rankArr[px] > rankArr[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rankArr[px]++;
        }
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1, 0);
        vector<int> cand1, cand2;

        // Step 1: find node with two parents
        for (auto &e : edges) {
            if (indegree[e[1]] == 0) {
                indegree[e[1]] = e[0];
            } else {
                cand1 = {indegree[e[1]], e[1]};
                cand2 = e;
                e[1] = 0;  // mark to skip
            }
        }

        parent.resize(n+1);
        rankArr.resize(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;

        // Step 2: DSU cycle check
        for (auto &e : edges) {
            if (e[1] == 0) continue;
            if (unite(e[0], e[1])) {
                if (cand1.empty()) return e;
                return cand1;
            }
        }

        return cand2;
    }
};
