class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // calculate and check if sum of all num is even
        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int target = sum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int num: nums) {
            vector<bool> new_dp(target + 1, false);
            new_dp[0] = true;
            for (int j = 1; j <= target; ++j) {
                if (j >= num) {
                    new_dp[j] = dp[j] || dp[j - num];
                } else {
                    new_dp[j] = dp[j];
                }
            }
            dp = new_dp;
        }
        return dp[target];
    }
};
