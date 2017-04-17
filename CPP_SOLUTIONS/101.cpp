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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return 1;
        return check(root -> left, root -> right);
    }
    
    bool check(TreeNode* lsub, TreeNode* rsub) {
        if(!lsub && !rsub) return 1;
        if(!lsub || !rsub) return 0;
        if(lsub -> val != rsub -> val) return 0;
        return check(lsub -> left, rsub -> right) && check(lsub -> right, rsub -> left);
    } 
};
