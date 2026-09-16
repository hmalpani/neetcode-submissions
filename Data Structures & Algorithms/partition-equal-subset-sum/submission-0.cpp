class Solution {
    vector<vector<int>> dp;

    bool dfs(vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        dp[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);

        return dp[i][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;

        dp.resize(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, target);
    }
};
