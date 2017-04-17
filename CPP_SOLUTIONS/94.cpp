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
    vector<int> res;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root -> left);
        res.push_back(root -> val);
        dfs(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
};
