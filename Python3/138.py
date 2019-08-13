__________________________________________________________________________________________________
sample 32 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    '''
    1) Iterate through original list 
    2) Keep a hashtable mapping each node to it's clone in 
    the new list
    3) Iterate once more, setting random to be the clone version 
    of the original 
    '''
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        if head == None: 
            return None
        
        old_to_new = {}
        new_list = Node(head.val, None, None)
        old_to_new[head] = new_list
        
        new_head = new_list
        curr = head
        
        while curr.next:
            new_list.next = Node(curr.next.val, None, None)
            
            old_to_new[curr.next] = new_list.next
            curr = curr.next
            new_list = new_list.next
            
        old = head
        curr = new_head
        while(curr):
            if old.random == None:
                curr.random = None
            else:
                curr.random = old_to_new[old.random]
            curr = curr.next
            old = old.next
            
        return (new_head)
__________________________________________________________________________________________________
sample 15300 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
        https://leetcode.com/problems/copy-list-with-random-pointer/discuss/261633/Python3-2-pass-solution-beats-100
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        #create a dummy head
        dummy = Node(-1, None, None)
        #create a dict to store the locations of old llist and cprresponding new llist
        nodemap = {}
        #pointer to the old llist
        cur = head
        #pointer to the new llist
        newcur = dummy
        
        while cur:
            #create a new node that copy from the old llist
            newNode = Node(cur.val, None, None)
            newcur.next = newNode
            newcur = newcur.next
            
            nodemap[cur] = newcur
            cur = cur.next
            
        cur = head
        newcur = dummy.next
        while cur:
            if cur.random:
                newcur.random = nodemap[cur.random]
            cur = cur.next
            newcur = newcur.next
        return dummy.next
__________________________________________________________________________________________________
