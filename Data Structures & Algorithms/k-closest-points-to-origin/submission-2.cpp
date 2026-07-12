class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxHeap;
        int i=0;
        while (i<k) {
            int dist = ((points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]));
            maxHeap.push({dist, i});
            ++i;
        }
        while (i<points.size()) {
            int dist = ((points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]));
            maxHeap.push({dist, i});
            maxHeap.pop();
            ++i;
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return ans;
    }
};
