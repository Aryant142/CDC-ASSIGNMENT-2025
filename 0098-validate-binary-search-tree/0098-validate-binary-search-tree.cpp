class Solution {
public:
    bool bst(TreeNode* root, long min, long max) {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max)
            return false;

        return bst(root->left, min, root->val) && 
               bst(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return bst(root, LONG_MIN, LONG_MAX);
    }
};
