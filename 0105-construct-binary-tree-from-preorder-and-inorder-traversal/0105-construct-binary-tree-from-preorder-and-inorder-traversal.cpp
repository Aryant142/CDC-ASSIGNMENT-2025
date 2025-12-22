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
    // find position of element in inorder
    int find(vector<int>& inorder, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (inorder[i] == element) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,
                    int inStart, int inEnd, int n) {
        // base case
        if (index >= n || inStart > inEnd) return nullptr;

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);

        int pos = find(inorder, element, n);

        // recursive calls
        root->left = solve(preorder, inorder, index, inStart, pos - 1, n);
        root->right = solve(preorder, inorder, index, pos + 1, inEnd, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        int n = inorder.size();
        return solve(preorder, inorder, preindex, 0, n - 1, n);
    }
};
