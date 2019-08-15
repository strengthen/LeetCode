__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda p: (-p[0], p[1]))
        
        queue = []
        for person in people:
            queue.insert(person[1], person)
        
        return queue
__________________________________________________________________________________________________
sample 13332 kb submission
from collections import deque
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        order = deque()
        people.sort(key = lambda x: (-x[0], x[1]))
        for pair in people:
            order.insert(pair[1], pair)

        return list(order)
__________________________________________________________________________________________________
