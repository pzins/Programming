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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(!head) return nullptr;
        ListNode *a, *b;
        int size = 0;
        a = head;
        b = head;
        while(a)
        {
            a = a->next;
            size++;
        }
        a = head;
        k = k % size;
        if(k == 0) return head;
        int counter = 0;
        while(counter < k)
        {
            b = b->next;
            counter++;
        }
        ListNode* tmp;
        while(b->next)
        {
            a = a->next;
            b = b->next;
        }
        b->next = head;
        head = a->next;
        a->next = nullptr;
        return head;
    }
};
