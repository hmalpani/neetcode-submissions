class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s: strs) {
            vector<int> char_count(26,0);
            for (char c: s) {
                ++char_count[c - 'a'];
            }
            string key = to_string(char_count[0]);
            for (int i=1; i<26; ++i) {
                key += ',' + to_string(char_count[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
