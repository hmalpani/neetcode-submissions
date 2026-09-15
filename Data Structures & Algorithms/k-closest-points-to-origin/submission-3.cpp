class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto point: points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, point});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
