__________________________________________________________________________________________________
sample 44 ms submission
cache = {}
class Solution(object):
    def countArrangement(self, N):
        def helper(i, X):
            if i == 1:
                return 1
            key = i, X
            if key in cache:
                return cache[key]
            total = sum(helper(i - 1, X[:j] + X[j + 1:])
                        for j, x in enumerate(X)
                        if x % i == 0 or i % x == 0)
            cache[key] = total
            return total
        return helper(N, tuple(range(1, N + 1)))
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def countArrangement(self, N: int) -> int:
        if N < 2:
            return 1
        # i % nums[i] == 0 or
        # num[i] % i == 0
        result = [0]
        visited = [False] * N
        self.countHelper(N, visited, result)
        return result[0]
    def countHelper(self, N, visited, result):
        # while N > 0:
        # if N > 0:
        if N == 0:
            result[0] = result[0] + 1
            return
        for i in range(len(visited)):
            if (N % (i+1) == 0 or (i+1) % N == 0) and (not visited[i]):
                visited[i] = True
                self.countHelper(N-1, visited, result)
                visited[i] = False
__________________________________________________________________________________________________
