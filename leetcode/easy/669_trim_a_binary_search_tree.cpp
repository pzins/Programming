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
    
    
    TreeNode* insert(TreeNode* root, int val)
    {
        TreeNode* n = root;
        TreeNode* p = n;
        TreeNode* o = new TreeNode(val);
        if(root == NULL) root = o;
        else
        {
            while(n)
            {
                p = n;
                if(n->val < val) n = n->right;
                else n = n->left;
            }
            if(p->val < val)
            {
                p->right = o;    
            }
            else
            {
                p->left = o;
            }
        }
        return root;
    }
    
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* r = NULL;
        while(q.size() > 0)
        {
           
            TreeNode* tmp = q.front();
            int v = tmp->val;
            
            if(v <= R && v >= L)
            {
                if(!r)
                    r = insert(r, v);
                else
                    insert(r, v);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(v > R && tmp->left)
            {
                q.push(tmp->left);
            }
            if(v < L && tmp->right)
            {
                q.push(tmp->right);
            }
            q.pop();
        }
        return r;
    }
};