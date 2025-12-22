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

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& index,
                    int inStart, int inEnd, int n) {
        // base case
        if (index < 0 || inStart > inEnd) return nullptr;

        int element = postorder[index--];  // take element from end
        TreeNode* root = new TreeNode(element);

        int pos = find(inorder, element, n);

        // IMPORTANT: build right subtree first, then left subtree
        root->right = solve(postorder, inorder, index, pos + 1, inEnd, n);
        root->left  = solve(postorder, inorder, index, inStart, pos - 1, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIndex = n - 1;  // start from last element of postorder
        return solve(postorder, inorder, postIndex, 0, n - 1, n);
    }
};
