__________________________________________________________________________________________________
sample 332 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        #corner case
        if head == None: return None
        LinkList = []
        while head:
            LinkList.append(head.val)
            head = head.next
        res = [0]*len(LinkList)
        stack = []
        for i in range(len(LinkList)):
            while stack and LinkList[i] > LinkList[stack[-1]]:
                res[stack.pop()] = LinkList[i]
            stack.append(i)
        
        return res                
__________________________________________________________________________________________________
sample 18484 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        
        """
        :type head: ListNode
        :rtype: List[int]
        """
        stack = []
        ans = []
        cnt = 0
        while head:
            ans.append(0)
            while stack and stack[-1][0] < head.val:
                tv, ti = stack.pop()
                ans[ti] = head.val
            stack.append((head.val, cnt))
            cnt += 1
            head = head.next
        return ans
__________________________________________________________________________________________________
