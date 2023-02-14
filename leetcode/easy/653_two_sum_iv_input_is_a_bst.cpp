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

void dfs(TreeNode* node, map<int, int>& m, int k)
{
    if(node != nullptr)
    {
        if(m.find(node->val) != m.end()) m[k - node->val]++;
        else m[k - node->val] = 1;

        dfs(node->left, m, k);
        dfs(node->right, m, k);
    }
}

void check(TreeNode* node, map<int, int>& m, int k, bool& r)
{
    if(node != nullptr)
    {
        if(r == false && m.find(node->val) != m.end()) {
            r = true;
            //cout << node->val << " " <<  m[node->val] << "  " << (node->val == (k / 2)) << endl;
            if((float(node->val) == (float(k) / 2)) && (m[node->val] <= 1)) r = false;
            //cout << r << endl;
        }
        check(node->left, m, k, r);
        check(node->right, m, k, r);
    }
}

public:
    bool findTarget(TreeNode* root, int k) {
        map<int, int> m;
        dfs(root, m, k);
        // for(auto a : m) cout << a.first << " " << a.second << endl;
        // cout << "------" << endl;
        bool res = false;
        check(root, m, k, res);
        return res;
    }
};
