__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    mp = {}
    
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        if N == 0:
            return cells
        res = [0]
        for i in range(1, len(cells) - 1):
            res.append(1 if cells[i-1] == cells[i+1] else 0)
        res.append(0)
        return self.prisonAfterNDays(res, (N - 1) % 14)
__________________________________________________________________________________________________
sample 12956 kb submission
class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        while N>0:
            cells2 = []
            cells2.append(0)
            for i in range(1, 7):
                val = 1 if cells[i-1]==cells[i+1] else 0
                cells2.append(val);
            cells2.append(0)
            cells = cells2
            N = (N - 1)%14 # needed or else timeout
            # N = N - 1 # brute force
        return cells;
__________________________________________________________________________________________________
