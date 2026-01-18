class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Get best path sum from left and right (ignore negatives)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Update global maximum (path passing through root)
        maxSum = max(maxSum, root->val + left + right);

        // Return best single-branch path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
