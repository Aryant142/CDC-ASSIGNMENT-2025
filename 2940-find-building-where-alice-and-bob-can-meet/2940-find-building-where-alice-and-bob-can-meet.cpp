class Solution {
public:
    vector<int> seg;
    int N;

    // Build segment tree
    void build(vector<int>& a, int n) {
        N = n;
        seg.assign(4 * n, -1);
        buildTree(a, 0, n - 1, 1);
    }

    void buildTree(vector<int>& a, int l, int r, int idx) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(a, l, mid, idx * 2);
        buildTree(a, mid + 1, r, idx * 2 + 1);
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    // Range Maximum Query
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return -1;
        if (ql <= l && r <= qr) return seg[idx];

        int mid = (l + r) / 2;
        return max(query(idx * 2, l, mid, ql, qr),
                   query(idx * 2 + 1, mid + 1, r, ql, qr));
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int n = heights.size();
        build(heights, n);

        vector<int> result;

        for (auto& q : queries) {
            int i = q[0], j = q[1];
            int L = min(i, j);
            int R = max(i, j);

            // Case 1: same index
            if (i == j) {
                result.push_back(i);
                continue;
            }

            // Case 2: right building already taller
            if (heights[R] > heights[L]) {
                result.push_back(R);
                continue;
            }

            // Correct rule: target = max height of the two
            int target = max(heights[i], heights[j]);

            // Now binary search for first index > R where height > target
            int lo = R + 1;
            int hi = n - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                int maxi = query(1, 0, n - 1, R + 1, mid);

                if (maxi > target) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};
