/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        
        vector<int> v;
        while(head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        
        vector<int> w = v;
        std::reverse(w.begin(), w.end());
        
        int res = 0;
        int val;
        for(int i = 0; i < v.size(); ++i)
        {
            val = v.at(i) + w.at(i);
            if(res < val) res = val;
        }
        return res;
    }
};
