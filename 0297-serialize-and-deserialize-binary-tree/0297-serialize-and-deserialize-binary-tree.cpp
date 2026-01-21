/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (!root) return "null,";

    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (!curr) {
            s += "null,";
            continue;
        }

        s += to_string(curr->val) + ",";
        q.push(curr->left);
        q.push(curr->right);
    }
    return s;
}


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;

    stringstream ss(data);
    string val;

    getline(ss, val, ',');
    if (val == "null" || val.empty()) return NULL;

    TreeNode* root = new TreeNode(stoi(val));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // LEFT
        if (getline(ss, val, ',')) {
            if (!val.empty() && val != "null") {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }
        }

        // RIGHT
        if (getline(ss, val, ',')) {
            if (!val.empty() && val != "null") {
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }
    }
    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));