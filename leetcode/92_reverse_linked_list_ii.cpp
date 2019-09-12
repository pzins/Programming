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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n == 1 || n == m) return head;
        
        if(!head) return nullptr;
        ListNode* curr = head;
        int cnt = 1;
        while(cnt < m-1)
        {
            curr = curr->next;
            if(!curr) return head;
            cnt++;
        }
        ListNode* tmp = curr;
        while(cnt < n)
        {
            tmp = tmp->next;
            cnt++;
        }        
        ListNode* pred = curr;
        curr = curr->next;
        
        if(curr == tmp)
        {
            pred->next = curr->next;
            tmp->next = pred;
            if(head == pred) return tmp;
            return head;
        }
        
        if(m == 1)
        {
            head = tmp;
        }
        else
        {
            pred->next = tmp;
            pred = curr;
            curr = curr->next;
        }
        
        
        pred->next = tmp->next;
        
        ListNode* succ = curr;
        while(curr != tmp)
        {
            succ = curr->next;            
            curr->next = pred;
            pred = curr;
            curr = succ;
        }
        curr->next = pred;
        return head;
    }
};
