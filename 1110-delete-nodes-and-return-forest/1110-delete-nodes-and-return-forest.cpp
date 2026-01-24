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
    TreeNode* helper(TreeNode* root, vector<int>& to_delete ,vector<TreeNode*>& res ,unordered_set<int> s){
        if(!root) return nullptr;
        root->left = helper(root->left,to_delete,res,s);
        root->right = helper(root->right,to_delete,res,s);
        if(s.find(root->val) != s.end()){
           if(root->left) res.push_back(root->left);
           if(root->right) res.push_back(root->right);
           return nullptr;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res ;
        unordered_set<int> s;
        for(auto & i: to_delete){
           s.insert(i);
        }
        if(s.find(root->val) == s.end()){
            res.push_back(root);
        }
        helper(root,to_delete,res,s);
        return res;
    }
};