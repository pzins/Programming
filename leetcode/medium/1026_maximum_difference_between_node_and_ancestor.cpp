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

void fct(TreeNode* n, int& maxi, vector<int> others) {
    if(n != nullptr)
    {
        int tmp = 0;
        for(int i = 0; i < others.size(); ++i)
        {
            tmp = max(abs(others[i]-n->val), tmp);
        }
        maxi = max(tmp, maxi);

        others.push_back(n->val);
        fct(n->left, maxi, others);
        fct(n->right, maxi, others);
    }
}

public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        vector<int> others = {};
        fct(root, res, others);
        return res;
    }
};
