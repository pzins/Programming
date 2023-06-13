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

    
    void fct(TreeNode* node, int key)
    {
        if(node != nullptr)
        {
            if(node->left != nullptr)
            {
                if(node->left->val == key)
                {
                    // leaves
                    if(node->left->left == nullptr && node->left->right == nullptr)
                    {
                        node->left = nullptr;
                    }
                    // only left child
                    else if(node->left->left == nullptr && node->left->right != nullptr)
                    {
                        node->left = node->left->right;
                    }
                    // onky right child
                    else if(node->left->left != nullptr && node->left->right == nullptr)
                    {
                        node->left = node->left->left;
                    }
                    // two children
                    else
                    {
                        TreeNode* mini = node->left->right;
                        TreeNode* prev = mini;
                        //no left child
                        if(mini->left == nullptr)
                        {
                            mini->left = node->left->left;
                            node->left = mini;
                        }
                        else
                        {
                            mini = mini->left;
                            while(mini->left != nullptr)
                            {
                                prev = mini;
                                mini = mini->left;
                            }
                            node->left->val = mini->val;
                            prev->left = mini->right;
                        }

                    }
                }
                else
                {
                    fct(node->left, key);
                }
            }
            if(node->right != nullptr)
            {
                if(node->right->val == key)
                {
                    // leaves
                    if(node->right->left == nullptr && node->right->right == nullptr)
                    {
                        node->right = nullptr;
                    }
                    // only left child
                    else if(node->right->left == nullptr && node->right->right != nullptr)
                    {
                        node->right = node->right->right;
                    }
                    // onky right child
                    else if(node->right->left != nullptr && node->right->right == nullptr)
                    {
                        node->right = node->right->left;
                    }
                    // two children
                    else
                    {
                        TreeNode* mini = node->right->right;
                        TreeNode* prev = mini;
                        //no left child
                        if(mini->left == nullptr)
                        {
                            mini->left = node->right->left;
                            node->right = mini;
                        }
                        else
                        {
                            mini = mini->left;
                            while(mini->left != nullptr)
                            {
                                prev = mini;
                                mini = mini->left;
                            }
                            node->right->val = mini->val;
                            prev->left = mini->right;
                        }

                    }
                }
                else
                {
                    fct(node->right, key);
                }
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* virtual_root = new TreeNode(0);
        virtual_root->left = root;
        fct(virtual_root, key);
        return virtual_root->left;
    }
};
