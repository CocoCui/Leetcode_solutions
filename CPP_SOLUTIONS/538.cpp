//538. Convert BST to Greater Tree

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
    int dfs(TreeNode* root, int rvalue) {
        if(root == NULL) return 0;
        int r = dfs(root -> right, rvalue);
        int l = dfs(root -> left, rvalue + root -> val + r);
        int sum = r + l + root -> val;
        root -> val += r + rvalue;
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};
