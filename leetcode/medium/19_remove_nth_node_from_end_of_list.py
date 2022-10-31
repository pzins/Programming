# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        pt1 = head
        pt2 = head
        prev = head
        
        
        for i in range(n):
            pt2 = pt2.next

        if pt2 is None:
            return head.next
            
        while pt2 is not None:
            prev = pt1
            pt1 = pt1.next
            pt2 = pt2.next
        
        prev.next = pt1.next

        return head
