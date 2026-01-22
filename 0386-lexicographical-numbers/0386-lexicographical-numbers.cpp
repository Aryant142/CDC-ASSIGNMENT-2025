class Solution {
public:
    void solve(int start, int n, vector<int>& ans) {
        if (start > n)
            return;
        ans.push_back(start);

        for (int i = 0; i <= 9; i++) {
            int x = (start * 10) + i;
            if (x > n)
                break;
            solve(x, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++){
            if (i > n) break;
            solve(i, n, ans);
        }    
        return ans;
    }
};