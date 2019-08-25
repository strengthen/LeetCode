__________________________________________________________________________________________________
sample 48 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        sofar, dicti = [[dummy, 0]], {0: 0}
        while head:
            cur = sofar[-1][1] + head.val
            if cur in dicti:
                while sofar[-1][1] != cur:
                    del dicti[sofar.pop()[1]]
            else:
                dicti[cur] = len(sofar)
                sofar.append([head, cur])
            head = head.next
        node = None
        while sofar:
            sofar[-1][0].next = node
            node = sofar[-1][0]
            sofar.pop()
        return dummy.next
__________________________________________________________________________________________________
sample 52 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        seen = {0 : 0}
        acc = 0
        ans = []
        for i, num in enumerate(nums):
            acc += num
            ans.append(num)
            if acc in seen:
                ans = ans[:seen[acc]]
            else:
                seen[acc] = len(ans)
        dummy = ListNode(-1)
        cur = dummy
        for num in ans:
            node = ListNode(num)
            cur.next = node
            cur = cur.next
        return dummy.next
__________________________________________________________________________________________________
