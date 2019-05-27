__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        if len(customers) == X:
            return sum(customers)

        # Compute running total of currently unsatisfied customers
        # which could be satisfied if X were used here
        runningTotal = 0
        satisfiedTotal = 0
        for i in range(X):
            if grumpy[i] == 1:
                runningTotal += customers[i]
            else:
                satisfiedTotal += customers[i]

        maxTotal = runningTotal

        for i in range(len(customers)-X):
            if grumpy[i] == 1:
                runningTotal -= customers[i]

            if grumpy[i+X] == 1:
                runningTotal += customers[i+X]
            else:
                satisfiedTotal += customers[i+X]

            if runningTotal > maxTotal:
                maxTotal = runningTotal

        return satisfiedTotal + maxTotal
__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        if X == 0:
            return sum([customers[i] for i in range(len(customers)) if not grumpy[i]])
        if X == len(grumpy):
            return sum([customers[i] for i in range(len(customers))])
        if X == 1:
            return sum([customers[i] for i in range(len(customers)) if not grumpy[i]]) + max([customers[i] for i in range(len(customers)) if grumpy[i]])
        
        n = len(customers)
        st = 0
        ed = X
        max_val = sum([customers[i] for i in range(st, ed) if grumpy[i]])

        val = max_val
        while ed < n:
            if grumpy[st]:
                val -= customers[st]
            if grumpy[ed]:
                val += customers[ed]
            st+=1
            ed+=1
            if val > max_val:
                max_val = val
        return max_val + sum([customers[i] for i in range(len(customers)) if not grumpy[i]])
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def maxSatisfied(self, customers, grumpy, X):
        good, N = 0, len(grumpy)
        for i in range(N):
            if grumpy[i] == 0:
                good += customers[i]
                customers[i] = 0

        best, curr = 0, 0
        for i, c in enumerate(customers):
            curr += c
            if i >= X: curr -= customers[i - X]
            if curr > best: best = curr
        return good + best