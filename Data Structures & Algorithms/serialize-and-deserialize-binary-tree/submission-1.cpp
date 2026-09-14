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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "N";
        }
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) {
                res += "N,";
            } else {
                res += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* cur = q.front();
            q.pop();
            if (val != "N") {
                cur->left = new TreeNode(stoi(val));
                q.push(cur->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                cur->right = new TreeNode(stoi(val));
                q.push(cur->right);
            }
        }
        return root;
    }
};
