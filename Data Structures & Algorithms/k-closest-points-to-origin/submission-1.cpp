class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> minHeap;
        int i=0;
        while (i<k) {
            int dist = ((points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]));
            minHeap.push({dist, i});
            ++i;
        }
        while (i<points.size()) {
            int dist = ((points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]));
            minHeap.push({dist, i});
            minHeap.pop();
            ++i;
        }
        vector<vector<int>> ans;
        while (!minHeap.empty()) {
            ans.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return ans;
    }
};
