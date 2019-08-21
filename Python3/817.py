__________________________________________________________________________________________________
sample 104 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        G = set(G)
        c = 0
        mxc = 0
        while head:
            if head.val in G:
                c = 1
            else:
                mxc += c
                c=0
            head = head.next
        mxc+=c
        return mxc
__________________________________________________________________________________________________
sample 108 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        s = set(G)
        cnt = 0
        # only need first one
        while head:
            if head.val in s and (not head.next or head.next.val not in s):
                cnt += 1
            head = head.next
        
        return cnt
__________________________________________________________________________________________________
