__________________________________________________________________________________________________
sample 76 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        def reverse(head):
            if not head or not head.next:
                return head
            
            pre = None
            while head:
                tmp = head.next
                head.next = pre
                pre = head
                head = tmp
            return pre

        if not head or not head.next:
            return
        
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        l2 = slow.next
        slow.next = None
        l2 = reverse(l2)
        
        l1 = head
        while l2:
            tmp = l1.next
            l1.next = l2
            l2 = l2.next
            l1.next.next = tmp
            l1 = tmp
        return l1
__________________________________________________________________________________________________
sample 21732 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self,head):
        if not head or not head.next:
            return head
        newhead=None   #设置新的头节点为None
        while head:
            p=head
            head=head.next
            p.next=newhead
            newhead=p
        return newhead 
    def reorderList(self, head):
        if not head or not head.next or not head.next.next:
            return 
        dummy=ListNode(0)
        dummy.next=head
        slow=fast=dummy
        while  fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        headB=self.reverseList(slow.next)

        headA=dummy.next
        slow.next=None
        new=ListNode(0)
        p=new
        while headA and headB:
            p.next=headA
            headA=headA.next
            p.next.next=headB
            headB=headB.next
            p=p.next.next
        if headB:
            p.next=headB
        head=new.next    
__________________________________________________________________________________________________
