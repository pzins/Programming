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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> levels;
        int maxi = root->val;
        int res = 1;

        map<int, int> data;

        q.push(root);
        levels.push(1);

        while(q.size() > 0)
        {
            TreeNode* t = q.front();
            int lvl = levels.front();

            if(t->left != nullptr)
            {
                q.push(t->left);
                levels.push(lvl+1);
            }

            if(t->right != nullptr)
            {
                q.push(t->right);
                levels.push(lvl+1);
            }

            if(data.find(lvl) == data.end())
            {
                data[lvl] = t->val;
            }
            else
            {
                data[lvl] += t->val;
            }
            q.pop();
            levels.pop();
        }
        
        
        for(auto a : data)
        {
            if(a.second > maxi)
            {
                maxi = a.second;
                res = a.first;
            }

        }
        return res;
    }
};
