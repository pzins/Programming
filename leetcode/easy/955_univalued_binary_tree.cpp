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
    
    bool rec(TreeNode* n, int v)
    {
        bool l = true;
        bool r = true;
        if(n->left) l = rec(n->left, v);
        if(n->right) r = rec(n->right, v);
        return l && r && n->val == v;
    }
    
    bool isUnivalTree(TreeNode* root) {
        return rec(root, root->val);
    }
};
