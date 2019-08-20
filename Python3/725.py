__________________________________________________________________________________________________
sample 28 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def LinkedListLength(self,head):
        if(head==None):
            return 0
        if(head.next==None):
            return 1
        count = 0
        while(head.next):
            head = head.next
            count+=1
        return count+1
    
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        
        list = [None for i in range(k)]
        head = root
        length = self.LinkedListLength(head)
        valuesInEachSection = length//k
        reaminingNumbers = length-valuesInEachSection*k
        nodesCountArray = [valuesInEachSection for i in range(k)]
        i = 0
        while(reaminingNumbers):
            nodesCountArray[i]+=1
            reaminingNumbers-=1
            i+=1
            
        for i,k in enumerate(nodesCountArray):
            list[i] = head
            k-=1
            while(k  and head):
                head = head.next
                k-=1
            if(head):
                p1 = head.next
                head.next = None
                head = p1
        return list
__________________________________________________________________________________________________
sample 13316 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        cur, length = root, 0
        while cur:
            cur, length = cur.next, length + 1
        chunk_size, longer_chunks = length // k, length % k
        res = [chunk_size+1] * longer_chunks + [chunk_size] * (k - longer_chunks)
        prev, cur = None, root
        for index, num in enumerate(res):
            if prev:
                prev.next = None
            res[index] = cur
            for i in range(num):
                prev, cur = cur, cur.next
        return res
__________________________________________________________________________________________________
