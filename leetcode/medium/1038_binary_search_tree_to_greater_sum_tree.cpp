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
    
    void traverse(TreeNode* n, vector<int>& v)
    {
        if(n)
        {
            v.at(n->val) = n->val;
            traverse(n->left, v);
            traverse(n->right, v);
        }
    }
    
    void transform(TreeNode* n, vector<int>& v)
    {
        if(n)
        {
            if(n->val == 0) n->val = v.at(v.size()-1);
            else n->val = v.at(v.size()-1) - v.at(n->val-1);
            transform(n->left, v);
            transform(n->right, v);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v(100,0);
        traverse(root, v);
        
        int curr = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            v.at(i) += curr;
            curr = v.at(i);
        }

        transform(root, v);
        
        return root;
    }
};
