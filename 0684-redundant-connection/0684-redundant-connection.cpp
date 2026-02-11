class Solution {
public:
    vector<int> parentArr, rankArr;

    int findParent(int x) {
        if (parentArr[x] != x)
            parentArr[x] = findParent(parentArr[x]);
        return parentArr[x];
    }

    bool unite(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);

        if (px == py)
            return true; // redundant edge

        if (rankArr[px] < rankArr[py])
            parentArr[px] = py;
        else if (rankArr[px] > rankArr[py])
            parentArr[py] = px;
        else {
            parentArr[py] = px;
            rankArr[px]++;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parentArr.resize(n + 1);
        rankArr.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parentArr[i] = i;

        for (auto& e : edges) {
            if (unite(e[0], e[1])) {
               return e;
            }
        }
        return {};
    }
};