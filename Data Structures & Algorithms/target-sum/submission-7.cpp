class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> newDp;
            for (auto x: dp) {
                newDp[x.first + nums[i]] += x.second;
                newDp[x.first - nums[i]] += x.second;
            }
            dp = newDp;
        }
        return dp[target];
    }
};
