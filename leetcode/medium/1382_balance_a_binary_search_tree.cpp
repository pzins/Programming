/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* n, vector<TreeNode*>& v) {
        if(n != nullptr)
        {
            inorder(n->left, v);
            v.push_back(n);
            inorder(n->right, v);
        }
    }
    
    TreeNode* build(int l, int r, vector<TreeNode*>& v)
    {
        if(l > r) return nullptr;
        int mid = l + (r-l) / 2;
        TreeNode* root = v.at(mid);
        root->left = build(l, mid-1, v);
        root->right = build(mid+1, r, v);
        return root;
        
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        TreeNode* res = build(0, v.size()-1, v);
        return res;
    }
};
