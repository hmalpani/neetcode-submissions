/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool sortHelper(Interval a, Interval b) {
        if (a.start < b.start) return true;
        if (b.start < a.start) return false;
        return (a.end < b.end);
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), sortHelper);
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};
