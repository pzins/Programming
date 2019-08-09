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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        int cnt = 1;
        ListNode* curr = head;
        ListNode* first = head;
        ListNode* last = head;
        ListNode* next = head;
        
        
        
        while(curr)
        {
            first = curr->next;
            last = curr;
            
            if(!first) break;
            
            for(int i = 0; i < cnt; ++i)
            {
                if(last)
                    last = last->next;
            }
            if(!last)
            {
                last = NULL;
                next = NULL;
                break;
            }
            else
            {
                if(last->next)
                {
                    next = last->next;
                }
                else
                {
                    next = NULL;
                    break;
                }
            }



            last->next = next->next;
            curr->next = next;
            next->next = first;

            cnt++;
            curr = curr->next;
        }
        
        return head;
        
    }
};