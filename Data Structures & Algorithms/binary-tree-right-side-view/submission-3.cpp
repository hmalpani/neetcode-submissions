class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int x = q.size();
            for (int i=1; i<=x; ++i) {
                TreeNode *temp = q.front();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                if (i == x) {
                    ans.push_back(temp->val);
                }
                q.pop();
            }
        }
        return ans;
    }
};
