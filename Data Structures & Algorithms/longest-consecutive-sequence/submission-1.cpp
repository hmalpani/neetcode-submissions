class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& n: nums) {
            mp[n] = 1;
        }
        int ans = 0;
        for (const auto& [k, v]: mp) {
            if (!mp.contains(k - 1)) {
                int l = 1;
                while (mp.contains(k + l)) {
                    ++l;
                }
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
