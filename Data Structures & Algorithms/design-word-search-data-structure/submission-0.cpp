class TrieNode {
    public:
        TrieNode* children[26];
        bool eow;
        TrieNode() {
            for (int i=0; i<26; ++i) {
                children[i] = NULL;
                eow = false;
            }
        }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int x, TrieNode* root) {
        TrieNode* cur = root;
        for (int i=x; i<word.size(); ++i) {
            if (word[i] == '.') {
                for (int j=0; j<26; ++j) {
                    if (cur->children[j] && dfs(word, i+1, cur->children[j])) return true;
                }
                return false;
            } else {
                if (!cur->children[word[i]-'a']) return false;
                cur = cur->children[word[i]-'a'];
            }
        }
        return cur->eow;
    }
};
