class MedianFinder {
    priority_queue<int, vector<int>, less<int>> mins;
    priority_queue<int, vector<int>, greater<int>> maxs;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        mins.push(num);
        if (!maxs.empty() && mins.top() > maxs.top()) {
            maxs.push(mins.top());
            mins.pop();
        }
        if (mins.size() > maxs.size() + 1) {
            maxs.push(mins.top());
            mins.pop();
        }
        if (maxs.size() > mins.size() + 1) {
            mins.push(maxs.top());
            maxs.pop();
        }
    }
    
    double findMedian() {
        if (mins.size() == maxs.size()) {
            return (mins.top() + maxs.top()) / 2.0;
        } else if (mins.size() > maxs.size()) {
            return mins.top();
        } else {
            return maxs.top();
        }
    }
};
