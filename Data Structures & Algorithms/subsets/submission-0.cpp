class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = pow(2,n);
        vector<vector<int>> ans;
        for (int i=0; i<total; ++i) {
            vector<int> row;
            for (int j=0; j<n; ++j) {
                if (int(pow(2,j)) & i) {
                    row.push_back(nums[j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
