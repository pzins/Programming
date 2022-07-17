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
    ListNode* removeZeroSumSublists(ListNode* head) {
        while(head != nullptr && head->val == 0) head = head->next;
        ListNode a;
        a.next = head;
        head = &a;
        ListNode* curr = head->next;
        ListNode* res = head->next;
        ListNode* pred = head;
        
        while(pred != nullptr)
        {
            bool del = false;
            // cout << "###" << pred->val << "###" << endl;
            if(pred->next == nullptr) break;
            curr=pred->next;
            int cumSum = 0;
            // if(curr != nullptr)
            //     cout << "-------  " << curr->val << "--------" << endl;
            while(curr != nullptr)
            {
                cumSum += curr->val;
                // cout << curr->val <<  " =====> " << cumSum << endl;
                if(cumSum == 0)  {
                    pred->next = curr->next;
                    del = true;
                    break;
                }
                else {
                    curr = curr->next;
                }
            }
            if(!del)
                pred=pred->next;
        }
        return head->next;
        
        
    }
};
