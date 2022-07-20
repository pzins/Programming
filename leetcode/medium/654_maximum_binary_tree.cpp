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
    
    TreeNode* build(vector<int> nums) {
        int maxi = 0;
        int max = nums.at(0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums.at(i) > max) {
                max = nums.at(i);
                maxi = i;
            }
        }
        TreeNode* n = new TreeNode();
        n->val = max;
        vector<int> rv(nums.begin() + maxi+1, nums.end());
        if(rv.size() > 0)
            n->right = build(rv);
        vector<int> lv(nums.begin(), nums.begin() + maxi);
        if(lv.size() > 0)
            n->left = build(lv);
        return n;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* n = build(nums);
        return n;
    }
};
