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
    void dfs(TreeNode* root, int cur_depth, int& max_depth) {
        if (!root) {
            return;
        }
        cur_depth = cur_depth + 1;
        max_depth = max(max_depth, cur_depth);
        dfs(root->left, cur_depth, max_depth);
        dfs(root->right, cur_depth, max_depth);
        cur_depth -= 1;
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
