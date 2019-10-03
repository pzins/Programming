/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    void rec(Node* node, vector<int>& res)
    {
        for(int i = 0; i < node->children.size(); ++i)
        {
            rec(node->children.at(i), res);
        }
        res.push_back(node->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        rec(root, res);
        return res;
    }
};
