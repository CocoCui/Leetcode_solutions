class Solution {
public:
    int calculate(string s) {
        int l = 0;
        int sign = 1, last = 1;
        stack<int> st;
        string tmp;
        for(char c: s) if(c != ' ') tmp += c;
        s = tmp;
        while(l < s.size()) {
            int r = l + 1;
            if(s[l] == '+') sign = 1 * sign;
            else if(s[l] == '-') sign = -1 * sign;
            else if(s[l] == '*') sign = 2;
            else if(s[l] == '/') sign = 3;
            else {
                while(r < s.size() && s[r] >= '0' && s[r] <= '9') r ++;
                int term = atoi(s.substr(l, r - l).c_str());
                if(sign > 0) {
                    if(sign == 1) st.push(term);
                    else if(sign == 2) {
                        int t1 = st.top();
                        st.pop();
                        st.push(t1 * term);
                    }
                    else  {
                        int t1 = st.top();
                        st.pop();
                        st.push(t1 / term);
                    }
                } else {
                    if(sign == -1) st.push(-term);
                    else if(sign == -2) {
                        int t1 = st.top();
                        st.pop();
                        st.push(-t1 * term);
                    }
                    else  {
                        int t1 = st.top();
                        st.pop();
                        st.push(-t1 / term);
                    }
                }
                sign = 1;
            }
            l = r;
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
