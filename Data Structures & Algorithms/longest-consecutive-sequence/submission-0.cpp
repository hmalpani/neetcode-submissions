class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            mp[nums[i]] = 1;
        }
        int ans = 0;
        for (auto x:mp) {
            if (mp.find(x.first - 1) == mp.end()) {
                int l = 1;
                while (mp.find(x.first + l) != mp.end()) {
                    ++l;
                }
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
