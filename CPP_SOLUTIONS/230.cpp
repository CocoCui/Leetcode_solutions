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
    int count;
    int ans;
    void dfs(TreeNode* root, int k) {
        if(root == NULL) return;
        dfs(root -> left, k);
        if(k == ++count) {
            ans = root -> val;
            return;
        }
        dfs(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        dfs(root, k);
        return ans;
    }
};
