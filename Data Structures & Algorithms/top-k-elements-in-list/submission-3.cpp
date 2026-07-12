class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int n: nums) {
            count[n] += 1;
        }
        for (const auto& [key, val]: count) {
            freq[val].push_back(key);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int f: freq[i]) {
                res.push_back(f);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
