// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n < 2) return n;
        int celeb = 0, count = 0;
        for(int i = 1; i < n; i++) {
            if(knows(i, celeb)) {
                continue;
            } else {
                celeb = i;
                count = i + 1;;
            }
        }
        for(int i = 0; i < celeb; i++) {
            if(!knows(i, celeb)) return -1;
        }
        for(int i = 0; i < n; i++) {
            if(i == celeb) continue;
            if(knows(celeb, i)) return -1;
        }
        return celeb;
    }
};
