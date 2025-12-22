class Solution {
public:
    int ans;      // final answer
    int maxDepth; // track deepest depth

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        // First time reaching this depth -> update ans
        if (depth > maxDepth) {
            maxDepth = depth;
            ans = node->val;
        }

        dfs(node->left, depth + 1);   // left first
        dfs(node->right, depth + 1);  // then right
    }

    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        dfs(root, 0);
        return ans;
    }
};
