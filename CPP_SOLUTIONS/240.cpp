class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int y = 0, x = n - 1;
        while(y < m && x >= 0) {
            if(target == matrix[y][x]) return true;
            else if(target < matrix[y][x]) x --;
            else y ++;
        }
        return false;
    }
};
