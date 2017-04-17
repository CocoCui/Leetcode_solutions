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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int depth) {
        if(!root) return;
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root -> val);
        dfs(root -> left, depth + 1);
        dfs(root -> right, depth + 1);
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        res.clear();
        dfs(root, 0);
        for(int i = 1; i < res.size(); i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
