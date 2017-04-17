//127. Word Ladder

class Solution {
    vector<vector<int>> next;
    vector<int> visited;
    int minlen;
    bool connected(string& a, string& b) {
        bool diff = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                if(diff) return 0;
                diff = 1;
            }
        }
        return 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& nodes) {
        int begin = -1, end = -1;
        for(int j = 0; j < nodes.size(); j++) {
            if(nodes[j] == endWord) end = j;
            if(nodes[j] == beginWord) begin = j;
        }
        if(end == -1) return 0;
        if(begin == -1) {
            begin = nodes.size();
            nodes.push_back(beginWord);
        }
        int n = nodes.size();
        visited = vector<int>(n, 0);
        queue<pair<int, int>> que;
        que.push(make_pair(begin, 1));
        while(!que.empty()) {
            int cur = que.front().first;
            int depth = que.front().second;
            que.pop();
            if(cur == end) return depth;
            if(visited[cur]) continue;
            visited[cur] = 1;
            for(int i = 0; i < n; i++) {
                if(visited[i]) continue;
                if(connected(nodes[i], nodes[cur])) que.push(make_pair(i, depth + 1));
            }
        }
        return 0;
    }
};
