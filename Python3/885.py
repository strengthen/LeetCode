__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        up = down = r0
        left = right = c0
        direct = 0
        num = 1
        res = []
        while (num <= C*R):
            direct %= 4
            if direct == 0: 
                if up >= 0:
                    for i in range(max(0,left), min(right+1,C)):
                        res.append([up,i])
                        num += 1
                right += 1
            elif direct == 1:
                if right < C:
                    for i in range(max(0,up), min(down+1,R)):
                        res.append([i,right])
                        num += 1
                down += 1
            elif direct == 2:
                if down < R:
                    for i in reversed(range(max(0,left),min(right+1,C))):
                        res.append([down,i])
                        num += 1
                left -= 1
            elif direct == 3:
                if left >=0:
                    for i in reversed(range(max(0,up),min(down+1,R))):
                        res.append([i,left])
                        num += 1
                up -= 1
            direct += 1
        return res
__________________________________________________________________________________________________
sample 13924 kb submission
class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        solu = []
        count = 0
        for gap in range(0, max(R,C)):
            if 0 <= r0-gap < R:
                for j in range(max(c0-gap,0), min(c0+gap+1, C)):
                    solu.append([r0-gap, j])
                    count += 1
                    if count == R*C: return solu
            if 0 <= c0+gap+1 < C:
                for i in range(max(r0-gap,0), min(r0+gap+1, R)):
                    solu.append([i, c0+gap+1])
                    count += 1
                    if count == R*C: return solu
            if 0 <= r0+gap+1 < R:
                for j in range(min(c0+gap+1, C-1), max(c0-gap-1, -1), -1):
                    solu.append([r0+gap+1, j])
                    count += 1
                    if count == R*C: return solu
            if 0 <= c0-gap-1 < C:
                for i in range(min(r0+gap+1, R-1), max(r0-gap-1, -1), -1):
                    solu.append([i, c0-gap-1])
                    count += 1
                    if count == R*C: return solu
        return solu
__________________________________________________________________________________________________
