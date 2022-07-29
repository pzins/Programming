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
    
    void insert(TreeNode** curr, int v) {
        if(*curr == nullptr)
        {
            *curr = new TreeNode;
            (*curr)->val = v;
            // cout << "Create new node " << (*curr)->val << endl;
        }
        else
        {
            // cout << "Insert " << v << " in tree starting at "<< (*curr)->val << endl;
            TreeNode* n = (*curr);
            while(n != nullptr) {
                if(n->val > v)
                {
                    if(n->left == nullptr)
                    {
                        n->left = new TreeNode;
                        n->left->val = v;
                        break;
                    }
                    else
                    {
                        n = n->left;
                    }

                }
                else
                {
                    if(n->right == nullptr)
                    {
                        n->right = new TreeNode;
                        n->right->val = v;
                        break;
                    }
                    else
                    {
                        n = n->right;
                    }

                }
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = nullptr;
        cout << (head==nullptr) << endl;
        for(auto& a : preorder)
        {
            insert(&head, a);
        }
        return head;
    }
};
