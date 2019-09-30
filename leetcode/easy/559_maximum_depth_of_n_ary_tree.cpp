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
    
    int run(Node* n)
    {
        if(n)
        {
            int maxi = 0;
            for(auto c : n->children)
            {
                int tmp = run(c);
                if(tmp > maxi)
                    maxi = tmp;
            }
            return maxi + 1;
        }
        return 0;
    }
    
    int maxDepth(Node* root) {
        return run(root);
    }
};
