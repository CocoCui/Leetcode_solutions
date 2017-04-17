/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(Interval &a, Interval &b) {
    if(a.start < b.start) return 1;
    else if(a.start == b.start) return a.end > b.end;
    return 0;
}
class Solution {
public:
    priority_queue<int> rooms;
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.size() < 2) return intervals.size();
        rooms.push(-intervals[0].end);
        for(int i = 1; i < intervals.size(); i++) {
            int early = - rooms.top();
            if(early <= intervals[i].start) rooms.pop();
            rooms.push(-intervals[i].end);
        }
        return rooms.size();
    }
};
