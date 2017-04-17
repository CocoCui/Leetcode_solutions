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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        queue<int> deep;
        vector<vector<int>> res;
        if(!root) return res;
        que.push(root);
        deep.push(0);
        vector<int> row;
        while(!que.empty()) {
            int curdeep = deep.front();
            TreeNode* n = que.front();
            que.pop();
            deep.pop();
            if(!n) continue;
            if(res.size() == curdeep) res.push_back(vector<int>());
            res[curdeep].push_back(n -> val);
            que.push(n -> left);
            que.push(n -> right);
            deep.push(curdeep + 1);
            deep.push(curdeep + 1);
        }
        return res;
    }
}
