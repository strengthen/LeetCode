__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def findKthNumber(self, n, k):
        k -= 1
        cur = 1
        while k > 0:
            step, first, last = 0, cur, cur + 1
            while first <= n:
                step += min(n + 1, last) - first
                first *= 10
                last *= 10
            if step <= k:
                cur += 1
                k -= step
            else:
                cur *= 10
                k -= 1
        return cur
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def getSteps(cur):
            steps, n1, n2 = 0, cur, cur + 1
            while n1 <= n:
                steps += min(n + 1, n2) - n1
                n1, n2 = n1 * 10, n2 * 10
            return steps
        cur, k = 1, k - 1
        while k > 0:
            steps = getSteps(cur)
            if steps <= k: k, cur = k - steps, cur + 1
            else: cur, k = cur * 10, k - 1
        return cur
__________________________________________________________________________________________________
