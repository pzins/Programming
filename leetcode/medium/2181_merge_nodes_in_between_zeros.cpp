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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* wr = head;
        ListNode* pred = head;
        int tmp = 0;
        while(curr != nullptr)
        {
            while(curr->val != 0) {
                tmp += curr->val;
                curr = curr->next;
            }
            wr->val = tmp;
            pred = wr;
            wr = wr->next;
            tmp = 0;
            curr = curr->next;
            if(curr == nullptr)
            {
                pred->next = nullptr;
                break;
            }
        }
        return head;       
    }
};
