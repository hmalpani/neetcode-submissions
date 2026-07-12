class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            mp[nums[i]] += 1;
        }
        vector<vector<int>> vec(n+1);
        for (auto x: mp) {
            vec[x.second].push_back(x.first);
        }
        vector<int> ans;
        for (int i=n; i>=0 && ans.size()<k; --i) {
            for (auto x: vec[i]) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
