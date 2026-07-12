class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] += 1;
        }
        vector<vector<int>> temp;
        for (const auto& [key, value]: mp) {
            temp.push_back({value, key});
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for (int i = temp.size() - 1; i >= 0 && k > 0; --i, --k) {
            ans.push_back(temp[i][1]);
        }
        return ans;
    }
};
