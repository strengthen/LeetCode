__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        d = query_row - query_glass
        q = collections.deque([(0, 0, poured)])
        while q:
            r, c, w = q.popleft()
            if r == query_row and c == query_glass:
                return min(1.0, w)
            if w > 1.0 and c >= (r-d) and c <= query_glass:
                w = (w-1.0)/2.0
                if q and q[-1][1] == c:
                    q[-1][2] += w
                else:
                    q.append([r+1, c, w])
                q.append([r+1, c+1, w])
        return 0.0
__________________________________________________________________________________________________
sample 13092 kb submission
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        cur = [poured]
        for i in range(query_row):
            curLen = len(cur)
            next = [0] * (curLen + 1)
            for j in range(len(cur)):
                if cur[j] <= 1:
                    continue
                halfFall = (cur[j] - 1) / 2
                next[j] += halfFall
                next[j+1] += halfFall
            cur = next
        return min(cur[query_glass], 1)
__________________________________________________________________________________________________
