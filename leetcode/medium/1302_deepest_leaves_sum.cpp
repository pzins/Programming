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
    
    int dfs(int depth, TreeNode* curr, map<int, int>& data)
    {
        if(curr)
        {
            if(data.find(depth) == data.end())
            {
                data[depth] = curr->val;
            }
            else
            {
                data[depth] += curr->val;
            }
            
            int maxL = 0;
            int maxR = 0;
            if(curr->left)
            {
                maxL = dfs(depth+1, curr->left, data);
            }
            if(curr->right)
            {
                maxR = dfs(depth+1, curr->right, data);
            }
            if(!curr->left && !curr->right) return depth;
            return max(maxR, maxL);
        }
        return 0;
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        map<int, int> data;
        int res = dfs(0, root, data);
        return data[res];
        
    }
};
