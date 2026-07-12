class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            mp[nums[i]] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto x: mp) {
            pq.push({x.second, x.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        for (int i=0; i<k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
