class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto& num: nums) {
            mp[num] += 1;
        }
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); ++j) {
                mp[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int target = -(nums[i] + nums[j]);
                if (mp[target] > 0) {
                    ans.push_back({nums[i], nums[j], target});
                }
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                mp[nums[j]]++;
            }
        }
        return ans;
    }
};
