/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return istree(root->left, root->right);
    }

    bool istree(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;              // both null
        if (!r1 || !r2) return false;             // one null
        if (r1->val != r2->val) return false;     // values differ

        return istree(r1->left, r2->right) &&     // left ↔ right
               istree(r1->right, r2->left);       // right ↔ left
    }
};
