class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct(n, 0);
        vector<int> postProduct(n, 0);
        preProduct[0] = 1;
        postProduct[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            preProduct[i] = preProduct[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            postProduct[i] = postProduct[i + 1] * nums[i + 1];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[i] = preProduct[i] * postProduct[i];
        }
        return ans;
    }
};
