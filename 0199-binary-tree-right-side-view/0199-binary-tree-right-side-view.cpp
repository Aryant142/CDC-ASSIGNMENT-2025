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
     void dsf(TreeNode* root, int dep, vector<int>& res) {
        if (!root)
            return;

        if (dep == res.size())
            res.push_back(root->val);

        dsf(root->right, dep + 1, res);
        dsf(root->left, dep + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dsf(root, 0, res);
        return res;
    }
};