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


struct comp{
    bool operator()(const Interval &i1, const Interval & i2) const {
        if (i1.start < i2.start){return true;}
        else{return false;}
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <=1){return true;}
        std::sort(intervals.begin(),intervals.end(),comp());
        int sz = intervals.size();
        for (int i=1; i<sz; i++){
            if(intervals[i].start < intervals[i-1].end){return false;}
        }
        return true;
    }
};
