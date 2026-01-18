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
   pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

     
        int notTake = max(left.first, left.second) +
                      max(right.first, right.second);

      
        int take = root->val + left.first + right.first;

        return {notTake, take};
    }

    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};