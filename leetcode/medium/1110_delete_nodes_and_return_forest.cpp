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

    void fct(TreeNode* node, unordered_set<int>& to_delete, vector<TreeNode*>& res, TreeNode* parent, string mode)
    {
        if(node != nullptr)
        {
            fct(node->left, to_delete, res, node, "L");
            fct(node->right, to_delete, res, node, "R");
            
            if(to_delete.count(node->val))
            {
                if(node->left != nullptr)
                {
                    res.push_back(node->left);
                    node->left = nullptr;
                }

                if(node->right != nullptr)
                {
                    res.push_back(node->right);
                    node->right = nullptr;
                }
                if(mode == "L")
                {
                    parent->left = nullptr;
                }
                else if(mode == "R")
                {
                    parent->right = nullptr;
                }
            }
            else if(parent == nullptr) res.push_back(node);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s;
        for(auto a: to_delete) s.insert(a);
        fct(root, s, res, nullptr, "A");
        return res;
    }
};
