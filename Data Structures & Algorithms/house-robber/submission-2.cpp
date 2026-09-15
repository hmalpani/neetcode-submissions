class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }
        int cur_1 = nums[2] + nums[0];
        int cur_2 = nums[1];
        int cur_3 = nums[0];
        for (int i = 3; i < n; ++i) {
            int temp = nums[i] + max(cur_2, cur_3);
            cur_3 = cur_2;
            cur_2 = cur_1;
            cur_1 = temp;
        }
        return max(cur_1, cur_2);
    }
};
