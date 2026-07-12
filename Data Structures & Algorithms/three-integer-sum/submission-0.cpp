class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
        unordered_map<int, unordered_map<int, int>> mp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=1; i<n-1; ++i) {
            int l = 0, r = n-1;
            while (l<i && i<r) {
                if (nums[l] + nums[i] + nums[r] == 0) {
                    if ((mp.find(nums[i]) != mp.end() && mp[nums[i]].find(nums[l]) == mp[nums[i]].end()) || mp.find(nums[i]) == mp.end()) {
                        vector<int> temp;
                        temp.push_back(nums[l]);
                        temp.push_back(nums[i]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        mp[nums[i]][nums[l]] = 1;
                    }
                    ++l;
                    --r;
                } else if (nums[l] + nums[i] + nums[r] < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans; 
    }
};
