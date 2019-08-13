__________________________________________________________________________________________________
sample 160 ms submission
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        S = set()
        while headA:
            S.add(headA)
            headA = headA.next
        
        while headB:
            if headB in S:
                return headB
            headB = headB.next
        
        return None        
__________________________________________________________________________________________________
sample 41644 kb submission
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA is None or headB is None:
            return None
        lenA = 0
        lenB = 0
        
        head = headA
        while head is not None:
            lenA += 1 
            head = head.next
        head = headB
        while head is not None:
            lenB += 1
            head = head.next
        
        while lenA != lenB:
            while lenA < lenB:
                lenB -= 1
                headB = headB.next
            while lenA > lenB:
                lenA -= 1
                headA = headA.next
                
        while headA != headB:
            headA = headA.next
            headB = headB.next
        
        if headA is not None:
            return headA
        else:
            return None
__________________________________________________________________________________________________
