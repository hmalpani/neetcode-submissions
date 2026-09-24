class TrieNode {
public:
    int idx;
    int refs;
    TrieNode* children[26];

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(string& word, int i) {
        TrieNode* cur = this;
        cur->refs++;
        for (char c: word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
    vector<string> res;

    int dfs(vector<vector<char>>& board, TrieNode* node, int r, int c, vector<string>& words) {
        int ROWS = board.size();
        int COLS = board[0].size();

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '*' || !node->children[board[r][c] - 'a']) {
            return 0;
        }

        char temp = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->children[temp - 'a'];
        int found = 0;
        if (node->idx != -1) {
            res.push_back(words[node->idx]);
            node->idx = -1;
            found++;
        }
        found += dfs(board, node, r + 1, c, words);
        found += dfs(board, node, r - 1, c, words);
        found += dfs(board, node, r, c + 1, words);
        found += dfs(board, node, r, c - 1, words);

        board[r][c] = temp;
        node->refs -= found;
        if (!node->refs) {
            prev->children[temp - 'a'] = nullptr;
        }
        return found;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            root->addWord(words[i], i);
        }

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                root->refs -= dfs(board, root, r, c, words);
            }
        }
        return res;
    }
};
