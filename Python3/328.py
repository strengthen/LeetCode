__________________________________________________________________________________________________
sample 36 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        cur = head
        even = ListNode(-1)
        evenhead = even
        while cur:
            even.next = cur.next
            even = even.next
            if not cur.next or not cur.next.next:
                cur.next = evenhead.next
                break
            cur.next = cur.next.next
            cur = cur.next
        return head
__________________________________________________________________________________________________
sample 14920 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        ans = head
        odd, even, d_o, d_e = head, head.next, head, head.next
        while d_o or d_e:
            if d_o:
                if d_o.next:
                    d_o.next = d_o.next.next
                    d_o = d_o.next
                else:
                    d_o = None
            if d_e:
                if d_e.next:
                    d_e.next = d_e.next.next
                    d_e = d_e.next
                else:
                    d_e = None
                
        while odd.next:
            odd = odd.next
            
        odd.next = even
        
        return ans
__________________________________________________________________________________________________
