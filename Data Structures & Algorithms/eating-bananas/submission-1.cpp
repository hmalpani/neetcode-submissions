class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ = INT_MIN;
        int n = piles.size();
        for (int i=0; i<n; ++i) {
            max_ = max(max_, piles[i]);
        }
        int l=1, r=max_;
        while (l<=r) {
            int mid = (l+r)/2;
            int hours = 0;
            for (int i=0; i<n; ++i) {
                hours += (piles[i] + mid - 1) / mid;
            }
            if (hours<=h) {
                r=mid-1;
            } else if (hours>h) {
                l=mid+1;
            }
        }
        return l;
    }
};
