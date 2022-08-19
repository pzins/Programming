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
    
//     int fct(TreeNode* n, int val, int k, int& res)
//     {
//         if(n->left)
//         {
//             val = fct(n->left, val, k, res);
//         }

//         if(n->right)
//         {
//             val = fct(n->right, val, k, res);
//         }
//         if(val == k)
//         {
//             res = n->val;
//         }
//         return 1 + val;
//     }
    
        
    void fct(TreeNode* n, int k, vector<int>& v)
    {
        if(v.size() < k) 
        {
        
        
            if(n->left)
            {
                fct(n->left, k, v);
            }
            v.push_back(n->val);
            if(n->right)
            {
                fct(n->right, k, v);
            }
        }
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
//         int res = 0;
//         int val = 0;
        
//         fct(root, val, k, res);
//         res = max(res, 1);
        
        vector<int> res;
        fct(root, k, res);
        for(auto& a: res) cout << a << " ";cout << endl;
        return res.at(k-1);
        
    }
};
