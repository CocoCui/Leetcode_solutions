#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;

unordered_map<string, int> dic;
vector<string> dicc;
unordered_map<int, set<int> > edges;
int connect(string a, string b) {
    int c = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) c++;
        if(c > 1) return 0;
    }
    return 1;
}
int findmin() {
    int m[dicc.size()], max = 2147483646;
    for(int i = 1; i < dicc.size(); i++) {
        m[i] = max;
    }
    m[0] = 0;
    for(int j = 0; j < dicc.size() - 1; j++) {
        for(int k = 0; k < dicc.size(); k++) {
            for(int nxt : edges[k]){
                //cout << dicc[k] << "--" << dicc[nxt] << ":" <<m[nxt] <<endl;
                m[nxt] = min(m[k] + 1, m[nxt]);
                //cout << dicc[k] << "--" << dicc[nxt] << ":" <<m[nxt] <<endl;
            }
        }
    }
    if(m[1] == 2147483647) return 0;
    else return m[1] + 1;
}

int bfs() {
    unordered_set<int> visit;
    queue<int> q;
    queue<int> dis;
    for(int n : edges[0]) {
        visit.insert(n);
        q.push(n);
        dis.push(2);
    }
    while(!q.empty()) {
        int nxt = q.front();
        int d = dis.front();
        q.pop();
        dis.pop();
        if(nxt == 1) return d;
        for(int n: edges[nxt]) {
            if(visit.find(n) == visit.end()) {
                q.push(n);
                dis.push(d + 1);
                visit.insert(n);
            }
        }
    }
    return 0;
}
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    dic[beginWord] = 0;
    dic[endWord] = 1;
    dicc.push_back(beginWord);
    dicc.push_back(endWord);
    for(string i: wordList){
        dic[i] = dicc.size();
        dicc.push_back(i);
    }
    for(int i = 0; i < dicc.size(); i++) {
        for(int j = i + 1; j < dicc.size(); j++) {
            //if(i == 0 && j == 1) continue;
            if(connect(dicc[i], dicc[j])) {
                //cout << dicc[i] << "----" << dicc[j] <<endl;
                edges[i].insert(j);
                edges[j].insert(i);
            }
        }
    }
    return bfs();
}

int main() {
    unordered_set<string> w;
    string a[] = {"hot","dot","dog","lot","log"};
    for(string s: a) w.insert(s);
    cout << ladderLength("hit","cog", w) <<endl;

}
