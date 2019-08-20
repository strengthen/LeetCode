__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def maximumSwap(self, num: int) -> int:
        A = list(map(int, str(num)))
        last = {x: i for i, x in enumerate(A)}
        currMax = 9
        for i, x in enumerate(A):
            for d in range(currMax, x, -1):
                if d in last and last[d] > i:
                    A[i], A[last[d]] = A[last[d]], A[i]
                    return int("".join(map(str, A)))
            currMax = x
        return num
__________________________________________________________________________________________________
sample 13056 kb submission
class Solution:
    # Greedy, Time O(n)
    def maximumSwap(self, num: int) -> int:
        num = list(map(int, str(num)))
        digitIndex = {x: i for i, x in enumerate(num)}
        for i, x in enumerate(num):
            for d in range(9, x, -1):
                if d in digitIndex and digitIndex[d] > i:
                    j = digitIndex[d]
                    num[i], num[j] = num[j], num[i]
                    return int(''.join(map(str, num)))
        return int(''.join(map(str, num)))
__________________________________________________________________________________________________
