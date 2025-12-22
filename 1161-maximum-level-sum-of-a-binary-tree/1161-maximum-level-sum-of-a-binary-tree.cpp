class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;        // current level
        int maxLevel = 0;     // answer
        int maxSum = INT_MIN; // track maximum sum

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
        }

        return maxLevel;  // return the level with maximum sum
    }
};
