class Solution {
    class TrieNode {
        public:
            bool isWord;
            unordered_map<char, TrieNode*> children;
            TrieNode() {
                isWord = false;
            }

            void addWord(const string& word) {
                TrieNode* cur = this;
                for (char c: word) {
                    if (!cur->children.count(c)) {
                        cur->children[c] = new TrieNode();
                    }
                    cur = cur->children[c];
                }
                cur->isWord = true;
            }
    };

    unordered_set<string> res;
    vector<vector<bool>> visit;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode *node, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || visit[r][c] || !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) {
            res.insert(word);
        }
        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);
        visit[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();

        for (const string& word: words) {
            root->addWord(word);
        }

        int ROWS = board.size();
        int COLS = board[0].size();

        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; ++j) {
                dfs(board, i, j, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
