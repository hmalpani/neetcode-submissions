class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0], cur = 0;
        for (auto num: nums) {
            if (cur < 0) {
                cur = 0;
            }
            cur += num;
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};
