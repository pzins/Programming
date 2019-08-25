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
    vector<vector<int>> levelOrder(Node* root) {
        
        queue<Node*> st;
        queue<int> lvl;
        st.push(root);
        lvl.push(0);
        vector<vector<int>> res;
        if(!root) return res;
        while(st.size() != 0)
        {
            Node* temp = st.front();
            int lv = lvl.front();
            
            
            if(lv >= res.size())
            {
                vector<int> t;
                res.push_back(t);
            }
            res.at(lv).push_back(temp->val);
            
            for(int i = 0; i < temp->children.size(); ++i)
            {
                st.push(temp->children.at(i));
                lvl.push(lv+1);
            }
            
            st.pop();
            lvl.pop();
        }
        return res;
    }
};
