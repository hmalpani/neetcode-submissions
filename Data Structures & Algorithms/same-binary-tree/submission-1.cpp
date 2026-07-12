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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        bool flag1 = false;
        if (!p->left && !q->left) flag1 = true;
        if (p->left && q->left) flag1 = (isSameTree(p->left, q->left));
        bool flag2 = false;
        if (!p->right && !q->right) flag2 = true;
        if (p->right && q->right) flag2 = (isSameTree(p->right, q->right));

        return flag1 && flag2;
    }
};
