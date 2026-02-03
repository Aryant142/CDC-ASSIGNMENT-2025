class Solution {
public:
    int moves = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left  = dfs(root->left);
        int right = dfs(root->right);

        moves += abs(left) + abs(right);

        return left + right + root->val - 1;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
