/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while(head && head->val == val) head = head->next;
        if(!head) return nullptr;
        ListNode* curr = head->next;
        ListNode* pred = head;
        while(curr)
        {
            if(curr->val == val)
            {
                pred->next = curr->next;
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
                pred = pred->next;
                
            }
        }
        return head;
    }
};
