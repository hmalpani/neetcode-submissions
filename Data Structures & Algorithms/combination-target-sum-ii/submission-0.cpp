class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, cur, target, 0, 0);
        return res;
    }

private:
    void dfs(vector<int>& candidates, vector<int>& cur, int target, int i, int total) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (total > target || i == candidates.size()) {
            return;
        }
        cur.push_back(candidates[i]);
        dfs(candidates, cur, target, i + 1, total + candidates[i]);
        cur.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        dfs(candidates, cur, target, i + 1, total);
    }
};
