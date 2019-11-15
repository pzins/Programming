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
   
    TreeNode* fct(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> qu;
        qu.push(node);
        while(qu.size())
        {
            TreeNode* n = qu.front();
            if(n->left && n->right)
            {
                int parent = contains(n, p, q);
                int left = contains(n->left, p, q);
                int right = contains(n->right, p, q);
                // cout << n->val << "   " << parent << " " << left << " " << right << endl;
                if( (parent == 2 && (left == 1 || right == 1)) || ( ((n == p && (left == 1 || right == 1)) ) || ( ((n == q) && (left == 1 || right == 1)) ) ))
                {
                    return n;
                }
                else
                {
                    if(n->left)
                        qu.push(n->left);
                    if(n->right)
                        qu.push(n->right);
                }
            }
            else if(n->left)
            {
                if((n == p || n == q) && contains(n->left, p, q) == 1)
                    return n;
                else
                    qu.push(n->left);
            }
            else if(n->right)
            {
                if((n == p || n == q) && contains(n->right, p, q) == 1)
                    return n;
                else
                    qu.push(n->right);
            }
            else
            {
                if(n->left)
                    qu.push(n->left);
                if(n->right)
                    qu.push(n->right);
            }
            qu.pop();
        }
        return node;
    }
    
    
    int contains(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> qu;
        qu.push(node);
        int pp = 0;
        int qq = 0;
        while(qu.size() != 0)
        {
            TreeNode* n = qu.front();
            qu.pop();
            if(p == n)
            {
                pp = 1;
                p = nullptr; 
            }
            else if(q == n)
            {
                qq = 1;
                q = nullptr;
            }
            if(!p && !q) break;
            if(n->left)
                qu.push(n->left);
            if(n->right)
                qu.push(n->right);
        }
        if(pp == 1 && qq == 1)
        {
            return 2;
        }
        else if(pp == 0 && qq == 0)
        {
            return 0;
        }
        else if(pp == 1)
        {
            return 1;
        }
        else
        {
            return 1;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        return fct(root, p, q);
    }
};
