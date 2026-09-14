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
    void dfs(TreeNode* root, int cur_max, int& ans) {
        if (!root) {
            return;
        }

        if (root->val >= cur_max) {
            cout<<root->val<<" ";
            ans++;
        }
        dfs(root->left, max(cur_max, root->val), ans);
        dfs(root->right, max(cur_max, root->val), ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }
};
