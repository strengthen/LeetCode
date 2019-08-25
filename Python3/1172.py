__________________________________________________________________________________________________
sample 452 ms submission
class DinnerPlates:

    def __init__(self, capacity: int):
        self.dat, self.pq, self.pool, self.c = [], [], set(), capacity

    def push(self, val: int) -> None:
        if not self.pool:
            self.dat.append([val])
            if len(self.dat[-1]) < self.c:
                self.pool.add(len(self.dat) - 1)
                heapq.heappush(self.pq, len(self.dat) - 1)
        else:
            while self.pq[0] not in self.pool:
                heapq.heappop(self.pq)
            self.dat[self.pq[0]].append(val)
            if len(self.dat[self.pq[0]]) == self.c:
                self.pool.remove(self.pq[0])
                heapq.heappop(self.pq)
 
    def pop(self) -> int:
        if self.dat:
            ans = self.dat[-1].pop()
            if not self.dat[-1]:
                if len(self.dat) in self.pool:
                    self.pool.remove(len(self.dat))
                self.pool.add(len(self.dat))
                self.dat.pop()
            return ans
        return -1      

    def popAtStack(self, index: int) -> int:
        if index >= len(self.dat) or not self.dat[index]:
            return -1
        if index not in self.pool:
            self.pool.add(index)
            heapq.heappush(self.pq, index)
        return self.dat[index].pop()

# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
__________________________________________________________________________________________________
class DinnerPlates:

    def __init__(self, capacity: int):
        self.queue = []
        self.c = capacity
        self.emp = [] #the non-full stacks, if the same index appears twice, that means it has two empty positions in this stack.

    def push(self, val: int) -> None:
        if self.emp:
            l = heapq.heappop(self.emp)
            self.queue[l] += [val]
            return
        if len(self.queue)>0 and len(self.queue[-1]) < self.c:
            self.queue[-1] += [val]
            return
        self.queue += [[val]]

    def pop(self) -> int:
        while len(self.queue) > 0 and not self.queue[-1]:
            self.queue.pop()
        if self.queue:
            res = self.queue[-1][-1]
            self.queue[-1].pop()
            return res
        return -1

    def popAtStack(self, index: int) -> int:
        if index < len(self.queue) and len(self.queue[index]) > 0:
            res = self.queue[index][-1]
            self.queue[index].pop()
            heapq.heappush(self.emp,index)
            return res
        return -1

__________________________________________________________________________________________________
