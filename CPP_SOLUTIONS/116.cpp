/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeLinkNode* r, TreeLinkNode* bro) {
        if(r == NULL) return;
        r -> next = bro;
        dfs(r -> left, r -> right);
        if(bro) dfs(r -> right, bro -> left);
        else dfs(r -> right, NULL);
    }
    void connect(TreeLinkNode *root) {
        dfs(root, NULL);
        return;
    }
};
