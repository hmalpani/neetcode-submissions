class PrefixTree {
    class TrieNode {
        public:
            bool isWord;
            TrieNode* children[26];
            TrieNode() {
                for (int i = 0; i < 26; ++i) {
                    children[i] = nullptr;
                }
                isWord = false;
            }
    };

    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char c: prefix) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};
