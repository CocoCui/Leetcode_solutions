/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(Interval& a, Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        if(intervals.size() == 0) return res;
        int s = intervals[0].start, e = intervals[0].end;
        for(int i = 0; i < intervals.size(); i++) {
            if(e >= intervals[i].start) e = max(intervals[i].end, e);
            else {
                res.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end;
            }
        }
        res.push_back(Interval(s, e));
        return res;
    }
};
