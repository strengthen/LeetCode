__________________________________________________________________________________________________
sample 64 ms submission
import itertools

class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        # check how many circles 
        # it is better to do a BFS
        n, b = len(A), list(B)
        min_step = float('inf')

        def backtracking(step, i):
            nonlocal min_step
            if step >= min_step:  # exceed min_step, early stop
                return

            while i < n and A[i] == b[i]:
                i += 1

            if i == n:
                min_step = min(step, min_step)
                return

            pos = []
            for j in range(i + 1, n):
                if b[j] == A[i]:
                    # should be the optimal swap, match two pairs in one swap,
                    # even if have multiple A[j]==b[i], we can just pick any one
                    if A[j] == b[i]:
                        pos = [j]
                        break
                    elif A[j] != b[j]:  # if A[j] == b[j], this swap also remain one mis-match, exclude this situation
                        pos.append(j)

            for k in pos:
                b[i], b[k] = b[k], b[i]
                backtracking(step + 1, i)
                b[i], b[k] = b[k], b[i]

        backtracking(0, 0)
        return min_step
__________________________________________________________________________________________________
sample 96 ms submission
class Solution(object):
    def kSimilarity(self, A, B):
        if A == B: return 0
        dq, seen, step, n = collections.deque([A]), {A}, 0, len(A)
        while dq:
            sz = len(dq)
            for _ in range(sz):
                cur, i = dq.popleft(), 0
                while i < n and cur[i] == B[i]: i += 1
                for j in range(i + 1, n):
                    if B[j] != cur[i] or cur[j] == B[j]: continue
                    nxt = cur[ : i] + cur[j] + cur[i + 1: j] + cur[i] + cur[j + 1: ]
                    if nxt not in seen:
                        seen.add(nxt)
                        if nxt == B: return step + 1
                        dq.append(nxt)
            step += 1
__________________________________________________________________________________________________
