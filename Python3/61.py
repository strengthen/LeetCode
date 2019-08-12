__________________________________________________________________________________________________
sample 28 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        last = head
        length = 1
        while last.next:
            last = last.next
            length = length + 1
        k = k % length
        last.next = head
        temp = head
        for _ in range(length - k - 1):
            temp = temp.next
        answer = temp.next
        temp.next = None
        
        return answer
__________________________________________________________________________________________________
sample 13028 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if (head == None):
            return None
        
        list = [head]
        n = 1
        current_node = head
        result = head
        
        while (current_node.next != None):
            n = n + 1
            current_node = current_node.next
            list.append(current_node)
        
        current_node.next = head
        rotations = n - k % n
        
        if (rotations != 0):
            current_node = list[rotations - 1]
            result = current_node.next
            current_node.next = None
        
        return result
__________________________________________________________________________________________________
