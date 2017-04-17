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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* suc = NULL;
        while(root -> val != p -> val) {
            if(p -> val < root -> val) {
                suc = root;
                root = root -> left;
            }
            if(p -> val > root -> val) root = root -> right;
        }
        if(root -> right) {
            root = root -> right;
            while(root -> left) root = root -> left;
            return root;
        }
        return suc;    
    }
};
