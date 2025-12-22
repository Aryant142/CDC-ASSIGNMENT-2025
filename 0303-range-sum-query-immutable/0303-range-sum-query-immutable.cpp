class NumArray {
public:
     int n;
    vector<int> seg;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, nums); 
    }
    void build(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*i + 1, l, mid, nums);
        build(2*i + 2, mid + 1, r, nums);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    int query(int L, int R, int i, int l, int r) {
        // completely outside
        if (R < l || r < L)
            return 0;

        // fully inside
        if (L <= l && r <= R)
            return seg[i];

        int mid = (l + r) / 2;

        return query(L, R, 2*i + 1, l, mid) +
               query(L, R, 2*i + 2, mid + 1, r);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */