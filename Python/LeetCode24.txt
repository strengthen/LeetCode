__________________________________________________________________________________________________
32ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: 'ListNode') -> 'ListNode':
        if head and head.next:
            temp = head.val
            head.val = head.next.val
            head.next.val = temp
            self.swapPairs(head.next.next)
        return head
__________________________________________________________________________________________________
36ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None: return head
        temp = head.next.next
        head, head.next = head.next, head
        head.next.next = self.swapPairs(temp)
        return head
__________________________________________________________________________________________________
40ms
def list_node_to_iter(n):
    while n is not None:
        yield n.val
        n = n.next

def reverse_by_n(it, n):
    while True:
        values = take_n(it, n)
        if len(values) < n:
            for e in values:
                yield e
            break
        else:
            for e in reversed(values):
                yield e

def list_node_from_iter(it):
    try:
        e = next(it)
    except StopIteration:
        return None

    root = ListNode(e)
    cur = root
    for e in it:
        node = ListNode(e)
        cur.next = node
        cur = node
    return root

def take_n(it, n):
    values = []
    while n:
        try:
            values.append(next(it))
        except StopIteration:
            break
        n -= 1
    return values

def swapPairs(head):
    return list_node_from_iter(reverse_by_n(list_node_to_iter(head), 2))

class Solution:
    def swapPairs(self, head):
        return swapPairs(head)
__________________________________________________________________________________________________
12100 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if not head or not head.next:
            return head
        
        fh=ListNode(0)
        fh.next=head
        
        p1=fh
        p2=head
        
        while p2 and p2.next:
            t=p2.next
            p2.next=t.next
            t.next=p2
            p1.next=t
            
            p1=p2
            p2=p2.next
        
        return fh.next
__________________________________________________________________________________________________
12136 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: 'ListNode') -> 'ListNode':
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            pre.next = b
            a.next = b.next
            b.next = a
            pre = a
        return self.next
__________________________________________________________________________________________________
