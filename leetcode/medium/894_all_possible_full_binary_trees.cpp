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
    
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        if (n % 2 == 0) return {};
        
        
        vector<vector<TreeNode*>> trees(n + 1);
        trees[1].push_back(new TreeNode{});
        
        for (int i = 3; i <= n; i += 2)
        {
            auto& currTrees = trees[i];
            
            for (int j = 1; j < i; j += 2)
            {
                for (TreeNode* tree : trees[j])
                {
                    for (TreeNode* otherTree : trees[i - j - 1])
                        currTrees.push_back(new TreeNode{ 0, tree, otherTree });
                }
            }
        }
        
        return trees[n];
    }
};
