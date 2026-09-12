class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 0;
        }
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        int n = wordList.size();
        int m = wordList[0].size();

        vector<vector<int>> adj(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[wordList[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < m; ++k) {
                    if (wordList[i][k] != wordList[j][k]) {
                        cnt++;
                    }
                }
                if (cnt == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        int res = 1;
        unordered_set<int> visited;

        for (int i = 0; i < m; ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == beginWord[i]) {
                    continue;
                }
                string word = beginWord.substr(0, i) + c + beginWord.substr(i +1);
                if (mp.contains(word) && !visited.contains(mp[word])) {
                    q.push(mp[word]);
                    visited.insert(mp[word]);
                }
            }
        }
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                if (wordList[node] == endWord) {
                    return res;
                }
                for (int neighbor_word: adj[node]) {
                    if (!visited.contains(neighbor_word)) {
                        visited.insert(neighbor_word);
                        q.push(neighbor_word);
                    }
                }
            }
        }
        return 0;
    }
};
