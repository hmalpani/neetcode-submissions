class Solution {
    int helper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int ist_house_inc = helper(nums, 0, nums.size() - 2);
        int ist_house_exc = helper(nums, 1, nums.size() - 1);

        return max(nums[0], max(ist_house_inc, ist_house_exc));
    }
};
