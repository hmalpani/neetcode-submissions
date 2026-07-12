class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<=r) {
            int mid = (l+r)/2;
            // cout<<nums[mid]<<" "<<l<<" "<<r<<" "<<mid<<"\n";
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l=mid+1;
            } else {
                r=mid-1;
            }
            // cout<<l<<" "<<r<<"\n";
        }
        return -1;
    }
};
