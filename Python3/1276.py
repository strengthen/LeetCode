__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        t=tomatoSlices
        c=cheeseSlices
        if t%2!=0 or t<2*c:
            return []
        t//=2
        j=t-c
        if t<2*j:
            return []
        s=t-2*j
        return [j,s]
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        return [] if ((tomatoSlices-2*cheeseSlices)%2) != 0 or (tomatoSlices-2*cheeseSlices) < 0 or (4*cheeseSlices-tomatoSlices) < 0 else list(((tomatoSlices-2*cheeseSlices)//2,(4*cheeseSlices-tomatoSlices)//2))
__________________________________________________________________________________________________
