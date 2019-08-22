__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def numMovesStonesII(self, stones):
        # window width
        st, ww = sorted(stones), len(stones)
        # core width
        i, coreb, coree, maxc = 0, 0, 0, 0
        for j in range(ww):
            while st[j] - st[i] >= ww:
                i += 1
            if j - i + 1 > maxc:
                coreb, coree, maxc = st[i], st[j], j - i + 1
        # min
        mini = ww - maxc + (1 if coree - coreb + 1 == maxc and maxc == ww - 1 and (coreb - 2 not in stones and coree + 2 not in stones) else 0)
        # max
        maxi = max(st[-2] - st[0] + 2 - ww, st[-1] - st[1] + 2 - ww)


        return [mini, maxi]
__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        n, low, leng = 0, len(stones), len(stones)
        high = max(stones[-1]-stones[1]-leng+2, stones[-2]-stones[0]-leng+2)
        
        for i in range(leng):
            while stones[i]-stones[n]+1 > leng:
                n += 1
            if i-n+1==leng-1 and stones[i]-stones[n]+1==leng-1:
                low = min(low, 2)
            else:
                low = min(low,leng-i+n-1)
        return [low, high]
__________________________________________________________________________________________________
