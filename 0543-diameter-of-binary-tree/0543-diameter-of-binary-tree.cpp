class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int lefth = height(root->left);
        int righth = height(root->right);
        return max(lefth, righth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int curdim = height(root->left) + height(root->right);

        return max(curdim, max(left, right));
    }
};
