__________________________________________________________________________________________________
60ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        d = {}
        for node in lists:
            cur = node
            while cur:
                if cur.val not in d:
                    # head, tail
                    d[cur.val] = [cur,cur]
                else:
                    d[cur.val][1].next = cur
                    d[cur.val][1] = cur
                cur = cur.next
        sorted_keys = sorted(list(d.keys()))
        
        for k in range(len(sorted_keys)-1):
            d[sorted_keys[k]][1].next = d[sorted_keys[k+1]][0]
        if sorted_keys:
            return d[sorted_keys[0]][0]
        else:
            return None
__________________________________________________________________________________________________
64ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return lists
        if len(lists) < 2:
            return lists[0]
        res = []
        for i in lists:
            while i:
                res.append(i)
                i = i.next
        
        
        res = sorted(res, key=lambda x: x.val)
        head = node = ListNode(None)
        for i in res:
            node.next = i
            node = i
        return head.next
__________________________________________________________________________________________________
68ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return
        
        temp = []
        for node in lists:
            curr = node
            while curr:
                temp.append((curr, curr.val))
                curr = curr.next
        
        temp = sorted(temp, key=lambda x: x[1])
        i = 0
        head = curr = ListNode(0)
        while i < len(temp):
            curr.next = temp[i][0]
            curr = curr.next
            i += 1
        
        return head.next
__________________________________________________________________________________________________
 15136 kb
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        res = []
        for i in range(len(lists)):
            while lists[i] != None:
                res.append(lists[i].val)
                lists[i] = lists[i].next
        res = sorted(res)
        return res
__________________________________________________________________________________________________
15172 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: 'List[ListNode]') -> 'ListNode':
        def mergeTwoLists(l1, l2):
            if not l1 or not l2:
                return l1 or l2
            head = ListNode(0)
            node = head
            while l1 and l2:
                if l1.val < l2.val:
                    node.next, l1 = l1, l1.next
                else:
                    node.next, l2 = l2, l2.next
                node = node.next
            node.next = l1 or l2
            return head.next
        
        if not lists:
            return None
        while len(lists) > 1:
            first_half = lists[::2]
            second_half = lists[1::2]
            temp_lists = first_half[-1:] if len(first_half) > len(second_half) else []
            for l1, l2 in zip(lists[::2], lists[1::2]):
                l_merged = mergeTwoLists(l1, l2)
                temp_lists.append(l_merged)
            lists = temp_lists
        return lists[0]
__________________________________________________________________________________________________
