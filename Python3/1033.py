__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        pos=[a,b,c]
        pos.sort()
        
        mi=2
        ma=pos[2]-pos[0]-2
        
        if ma==0:
            return [0,0]
        
        for i in range(1,3):
            if pos[i]-pos[i-1]<=2:
                mi=1
        return [mi,ma]
__________________________________________________________________________________________________
sample 12936 kb submission
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:

        a, b, c = sorted([a, b, c])
        if b-a==c-b==1:
            x = 0
        elif b-a in {1,2} or c-b in {1,2}:
            x = 1
        else: 
            x = 2
        y = max(c-a-2, 0)
        return x, y
__________________________________________________________________________________________________
