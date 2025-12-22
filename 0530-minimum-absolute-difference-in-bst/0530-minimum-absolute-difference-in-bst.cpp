/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderVals;

    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorderVals.clear();
        inorder(root);

        int minDiff = INT_MAX;
        for (int i = 1; i < inorderVals.size(); i++) {
            minDiff = min(minDiff, inorderVals[i] - inorderVals[i - 1]);
        }
        return minDiff;
    }
};