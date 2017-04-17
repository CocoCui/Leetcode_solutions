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
    bool valid(TreeNode* n, long long upper, long long lower) {
        if(n == NULL) return 1;
        if(n->val <= lower || n->val >= upper) return 0;
        return valid(n -> left, n -> val, lower) && valid(n -> right, upper, n -> val);
    }
    bool isValidBST(TreeNode* root) {
        long long upper = INT_MAX;
        upper += 1;
        long long lower = INT_MIN;
        lower -= 1;
        return valid(root, upper, lower);
    }
};
