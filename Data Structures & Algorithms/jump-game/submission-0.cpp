class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        dp[0] = true;
        for (int i=0; i<nums.size(); ++i) {
            if (dp[i]) {
                for (int j=1; j<=nums[i]; ++j) {
                    dp[i+j] = true;
                }
            } else return false;
        }
        return dp[nums.size()-1];
    }
};
