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
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxi = INT_MIN;
        dfs(root, count, maxi);
        return count;
    }
    void dfs(TreeNode* root, int& count, int maxi) {
        if (!root) return;
        if (root->val >= maxi) {
            ++count;
        }
        maxi = max(root->val, maxi);
        dfs(root->left, count, maxi);
        dfs(root->right, count, maxi);

    }
};
