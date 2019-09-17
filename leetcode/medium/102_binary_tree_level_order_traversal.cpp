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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<int> lvl;
        queue<TreeNode*> q;
        
        q.push(root);
        lvl.push(0);
        vector<vector<int>> res;
        if(!root) return res;
        while(q.size() != 0)
        {
            TreeNode* tmp = q.front();
            int l = lvl.front();
            if(tmp->left)
            {
                q.push(tmp->left);
                lvl.push(l+1);
            }
            if(tmp->right)
            {
                q.push(tmp->right);
                lvl.push(l+1);
            }
            q.pop();
            lvl.pop();
            if(l >= res.size())
            {
                vector<int> v{tmp->val};
                res.push_back(v);
            }
            else
            {
                res.at(l).push_back(tmp->val);
            }
        }
        return res;
    }
};
