/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Hnode
{
    int index;
    int val;
};
struct CustomCompare
{
    bool operator()(const Hnode& lhs, const Hnode& rhs)
    {
        return lhs.val > rhs.val;
    }
};

void printQueue(priority_queue<Hnode, vector<Hnode>, CustomCompare> q)
{
    while(q.size() > 0)
    {
        std::cout << q.top().val << " ";
        q.pop();
    }
    std::cout << endl;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Hnode, vector<Hnode>, CustomCompare> h;
        ListNode* res = new ListNode(0);
        ListNode* tail = res;
        int cnt = 0;
        for(auto& l : lists)
        {
            if(l != nullptr)
            {
                Hnode hnode;
                hnode.index = cnt;
                hnode.val = l->val;
                h.push(hnode);
            }
            cnt++;
        }
        while(h.size() > 0)
        {
            Hnode tmp = h.top();
            h.pop();
            ListNode* node = new ListNode(tmp.val);
            
            tail->next = node;
            tail = tail->next;
            lists.at(tmp.index) = lists.at(tmp.index)->next;
            if(lists.at(tmp.index) != nullptr)
            {
                Hnode hnode;
                hnode.index = tmp.index;
                hnode.val = lists.at(tmp.index)->val;
                h.push(hnode);
            }
        }
        return res->next;
    }
};
