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
    int pre_index = 0;
    unordered_map<int, int> inIndex;

    TreeNode* dfs(vector<int> preorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int root_val = preorder[pre_index];
        pre_index++;
        TreeNode* root = new TreeNode(root_val);
        int mid_index = inIndex[root_val];
        root->left = dfs(preorder, l, mid_index - 1);
        root->right = dfs(preorder, mid_index + 1, r);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inIndex[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() - 1);
    }
};
