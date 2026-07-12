class TrieNode {
    public:
        TrieNode* children[26];
        bool eow;
        TrieNode() {
            for (int i=0; i<26; ++i) {
                children[i] = NULL;
            }
            eow = false;
        }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->eow = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return cur->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c: prefix) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }
};
