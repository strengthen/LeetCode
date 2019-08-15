__________________________________________________________________________________________________
sample 72 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import random


class Solution:

    def __init__(self, head: ListNode):
        self.head = head
        self.count = self.to_count()
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        

    def getRandom(self) -> int:
        node = self.head
        p = random.random()//(1/self.count)
        for i in range(int(p)):
            node = node.next
        return node.val
        """
        Returns a random node's value.
        """
    
    def to_count(self):
        node = self.head
        count = 0
        while node is not None:
            count += 1
            node = node.next
        return count
    
# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
__________________________________________________________________________________________________
sample 15976 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from random import random

class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head
        pass

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        max_p = -1
        cur = self.head
        res = 0
        while cur:
            cur_p = random()
            if cur_p > max_p:
                res = cur.val
                max_p = cur_p
            cur = cur.next
                
        return res
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
__________________________________________________________________________________________________
