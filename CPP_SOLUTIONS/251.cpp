class Vector2D {
public:
    vector<int> list;
    int idx = 0;
    
    Vector2D(vector<vector<int>>& vec2d) {
        int h = vec2d.size();
        list.clear();
        idx = 0;
        if(h == 0) return;
        for(int i = 0; i < h; i++) {
            for(int n: vec2d[i]) list.push_back(n);
        }
        
        return;
    }

    int next() {
        return list[idx++];
    }

    bool hasNext() {
        return idx < list.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
