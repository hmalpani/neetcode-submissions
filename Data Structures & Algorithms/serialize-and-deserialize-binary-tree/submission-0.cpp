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
    void inorder(TreeNode* root, vector<string>& res) {
        if (!root) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        inorder(root->left, res);
        inorder(root->right, res);
    }

    TreeNode* build(vector<string>& vals, int& index) {
        if (vals[index] == "N") {
            ++index;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(vals[index]));
        ++index;
        root->left = build(vals, index);
        root->right = build(vals, index);
        return root;
    }

    vector<string> split(string& s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(vector<string>& vals, const string& delim) {
        ostringstream s;
        for (auto &val: vals) {
            if (&val != &vals[0]) {
                s << delim;
            }
            s << val;
        }
        return s.str();
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        inorder(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return build(vals, i);
    }
};
