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


vector<int> dfs(TreeNode* n, map<vector<int>, vector<TreeNode*>>& m)
{
    vector<int> res;
    if(n != nullptr)
    {
        vector<int> l = {};
        if(n->left != nullptr) l = dfs(n->left, m);

        vector<int> r = {};
        if(n->right != nullptr) r = dfs(n->right, m);

        // Just to make left and right different
        for(int i = 0; i < l.size(); ++i) l[i]+=1000;
        for(int i = 0; i < r.size(); ++i) r[i]+=10000;

        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), r.begin(), r.end());

        res.push_back(n->val);
        if(m.find(res) != m.end()) m[res].push_back(n);
        else m[res] = {n};
    }
    return res;
}


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<vector<int>, vector<TreeNode*>> m;
        vector<TreeNode*> res;
        dfs(root, m);
        for(auto a : m)
        {
            // for(auto b : a.first) cout << b << " ";
            // cout << "  ->  " << a.second.size() << endl;
            if(a.second.size() > 1)
            {
                res.push_back(a.second.at(0));
            }
        }
        return res;
    }
};
