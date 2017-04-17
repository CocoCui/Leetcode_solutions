class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0), visited(numCourses, 0);
        vector<vector<int>> next(numCourses,vector<int>());
        for(auto p: prerequisites) {
            in[p.first]++;
            next[p.second].push_back(p.first);
        }
        stack<int> zero;
        for(int i = 0; i < numCourses; i++) 
            if(in[i] == 0) zero.push(i);
        int take = 0;
        while(!zero.empty()) {
            take ++;
            int course = zero.top();
            zero.pop();
            for(int nxt: next[course]) {
                in[nxt] --;
                //cout << in[nxt] << endl;
                if(in[nxt] == 0) {
                    zero.push(nxt);
                }
            }
        }
        return take == numCourses;
    }
};
