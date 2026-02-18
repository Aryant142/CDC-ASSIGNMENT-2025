class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {effort, {x, y}}
        set<pair<int, pair<int,int>>> st;

        dist[0][0] = 0;
        st.insert({0, {0,0}});

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while (!st.empty()) {

            auto it = *(st.begin());
            st.erase(st.begin());

            int eff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n-1 && y == m-1)
                return eff;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx>=0 && ny>=0 && nx<n && ny<m) {

                    int newEff = max(
                        eff,
                        abs(heights[x][y] - heights[nx][ny])
                    );

                    if (newEff < dist[nx][ny]) {

                        // remove old value if exists
                        // if (dist[nx][ny] != INT_MAX)
                        //     st.erase({dist[nx][ny], {nx, ny}});

                        dist[nx][ny] = newEff;
                        st.insert({newEff, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};
