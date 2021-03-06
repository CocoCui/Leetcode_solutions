//543. Diameter of Binary Tree

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
    int maxlen;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        maxlen = max(maxlen, l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return maxlen - 1;
    }
};
