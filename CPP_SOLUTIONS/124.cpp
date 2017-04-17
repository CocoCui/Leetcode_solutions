/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPath;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        int sum = 0;
        if(l > 0) sum += l;
        if(r > 0) sum += r;
        maxPath = max(root -> val + sum, maxPath);
        return max(root -> val, root -> val + max(l, r));
    }
    
    int maxPathSum(TreeNode* root) {
        maxPath = INT_MIN;
        dfs(root);
        return maxPath;
    }
};
