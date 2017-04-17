//105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        //cout << pl << " " << pr << endl;
        //cout << il << " " << ir << endl;
        if(pl == pr) return NULL;
        TreeNode* node = new TreeNode(preorder[pl]);
        if(pl == pr - 1) return node;
        int i = il;
        for(; i < ir; i++) {
            if(inorder[i] == preorder[pl]) break;
        }
        int len_right = ir - i - 1;
        node -> left = build(preorder, pl + 1, pr - len_right, inorder, il, i);
        node -> right = build(preorder, pr - len_right, pr, inorder, i + 1, ir);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
