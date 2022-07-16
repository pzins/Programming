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
    
    void inorder(TreeNode* root, std::vector<int>& vec) {
        if(root != nullptr)
        {
            // cout << root->val << endl;
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        
        std::vector<int> v;
        inorder(root, v);
//         cout << v.size() << endl;
//         for(auto& i : v) cout << i << " ";
//         cout << endl;
        
        for(int i = 0; i < v.size() - 1; ++i)
        {
            if(v.at(i) >= v.at(i+1)) return false;
        }
        
        return true;
    }
};
