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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* left = head;
        ListNode* right = head;
        for(int i = 1; i < k; ++i) right = right->next;
        ListNode* saved = right;
        while(right->next != nullptr)
        {
            right = right->next;
            left = left->next;
        }
        int tmp = saved->val;
        saved->val = left->val;
        left->val = tmp;
        return head;
    }
};
