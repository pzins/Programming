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
    
    vector<int> fct(TreeNode* root, int& res) {
        if(root == nullptr) {
            return vector<int>{};
        }
        vector<int> l = fct(root->left, res);
        vector<int> r = fct(root->right, res);
        l.insert(l.end(), r.begin(), r.end());
        float sum = root->val;
        for(auto i : l) sum += i;
        sum = sum / (l.size() + 1);
        sum = floor(sum);
        if(sum == root->val) res++;
        
        l.push_back(root->val);
        return l;
    }
    
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        fct(root, res);
        return res;
    }
};
