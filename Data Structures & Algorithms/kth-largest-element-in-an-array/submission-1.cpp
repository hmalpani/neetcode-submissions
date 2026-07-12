class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int i=0;
        while (i<k) {
            min_heap.push(nums[i]);
            ++i;
        }
        while (i<nums.size()) {
            min_heap.push(nums[i]);
            min_heap.pop();
            ++i;
        }
        return min_heap.top();
    }
};
