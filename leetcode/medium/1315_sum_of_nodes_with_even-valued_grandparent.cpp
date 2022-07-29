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
    
    void traverse(TreeNode* n, TreeNode* p, TreeNode* gp, int& sum)
    {
        if(n)
        {
            if(p == nullptr)
            {
                traverse(n->left, n, nullptr, sum);
                traverse(n->right, n, nullptr, sum);
            }
            else if(gp == nullptr)
            {
                traverse(n->left, n, p, sum);
                traverse(n->right, n, p, sum);
            }
            else
            {
                if(gp->val % 2 == 0){
                    sum += n->val;
                }
                traverse(n->left, n, p, sum);
                traverse(n->right, n, p, sum);
            }
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        traverse(root, nullptr, nullptr, res);
        return res;
        
    }
};
