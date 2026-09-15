class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        int diff = min_heap.size() - max_heap.size();
        if (diff == 2) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (diff == -2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        int total = min_heap.size() + max_heap.size();
        if (total % 2 == 0) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        }
        return max_heap.top();
    }
};
