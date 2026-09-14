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
    int ans;

    // returns maximum sum from node to root;
    int find(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = find(root->left);
        int r = find(root->right);

        if (max(l, 0) + max(r, 0) + root->val > ans) {
            ans = max(l, 0) + max(r, 0) + root->val;
        }
        return root->val + max(max(l, 0), max(r, 0));
    }

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        find(root);
        return ans;
    }
};
