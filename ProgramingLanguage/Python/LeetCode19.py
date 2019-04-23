__________________________________________________________________________________________________
36ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head or (not head.next and n==1):
            return None
        t=0
        #这里需要dummy的原因是为了解决n和长度相等的问题（i.e.去掉list的第一个元素导致first.next不存在）
        dummy=ListNode(0)
        dummy.next=head
        first=dummy
        second=dummy
        #这一步是为了让firsrt先走n，和second有一个差距
        while t<n:
            t+=1
            first=first.next
        while first.next:
            first=first.next
            second=second.next
        second.next=second.next.next
        return dummy.next
__________________________________________________________________________________________________
40ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        cur=head
        target=1
        while target<n:
            target+=1
            cur=cur.next
        nth=cur
        cur=head
        prev=None
        while nth.next is not None:
            prev=cur
            cur=cur.next
            nth=nth.next
        if prev is None:
            return cur.next
        prev.next=cur.next
        return head      
__________________________________________________________________________________________________
44ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        length = 1
        copy = head
        while not copy.next is None:
            length+=1
            copy = copy.next
        copy2 = head
        prev = head
        for i in range(0, length):
            if(i < (length - n)):
                prev = head
                head = head.next
            else:
                if i == 0:
                    copy2 = copy2.next
                else:
                    prev.next = head.next
                break
        return copy2    
__________________________________________________________________________________________________
12208 kb
class Solution:
    def removeNthFromEnd(self, head: 'ListNode', n: 'int') -> 'ListNode':
        
        
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
        # Advances first pointer so that the gap between first and second is n nodes apart
        for i in range(1, n+2):
            first = first.next
        # Move first to the end, maintaining the gap
        while first is not None:
            first = first.next
            second = second.next
       
        second.next = second.next.next
        return dummy.next

__________________________________________________________________________________________________
12228 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: 'ListNode', n: 'int') -> 'ListNode':
        def to_list(list_node):
            converted_list = []
            while list_node is not None:
                converted_list.insert(0, list_node.val)
                list_node = list_node.next
            return converted_list
                
        def from_list(l1):
            list_node = ListNode(l1[0])
            l1 = l1[1:]
            while len(l1) != 0:
                temp_node = ListNode(l1[0])
                temp_node.next = list_node
                list_node = temp_node
                l1 = l1[1:]
            return list_node
        
        converted_list = to_list(head)
        if len(converted_list) == 0:
            return None
        del converted_list[n-1]
        if len(converted_list) == 0:
            return None
        return from_list(converted_list)
__________________________________________________________________________________________________
