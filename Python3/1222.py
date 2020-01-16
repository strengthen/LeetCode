__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        locations = {tuple(queen) for queen in queens}
        tags = set(range(8))
        x, y = king
        result = []
        for i in range(8):
            for index, loc in enumerate([[x, y+i], [x, y-i], [x+i, y], [x-i, y], [x-i, y-i], [x-i, y+i], [x+i, y-i], [x+i, y+i]]):
                if index in tags and tuple(loc) in locations:
                    result.append(loc)
                    tags.remove(index)
        return result
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        kx, ky = king
        ans=[]
        queens = set(map(tuple,queens))
        
        from itertools import repeat
        for i, rg in enumerate([
                   #0 horizontally: (kx, ky+1), (kx, ky+2), ...
                   zip(repeat(kx),range(ky+1,8)),
                   #1 horizontally: (kx, ky-1), (kx, ky-2), ...
                   zip(repeat(kx),reversed(range(0,ky))),
                   #2 vertically: (kx+1, ky), (kx+2, ky), ...
                   zip(range(kx+1,8),repeat(ky)),
                   #3 vertically: (kx-1, ky), (kx-2, ky), ...
                   zip(reversed(range(0,kx)),repeat(ky)),
                   #4 diagonally, ascending (kx+1,ky+1), (kx+2,ky+2), ...
                   zip(range(kx+1,8),range(ky+1,8)),
                   #5 diagonally, ascending (kx-1,ky-1), (kx-2,ky-2), ...
                   ##zip(reversed(range(max(kx-ky,0),kx)),reversed(range(max(ky-kx,0),ky))),
                   zip(reversed(range(kx-min(kx,ky),kx)),reversed(range(ky-min(kx,ky),ky))),
                   #6 diagonally, descending (kx+1,ky-1), (kx+2,ky-2)
                   zip(range(kx+1,8),reversed(range(ky-min(8-kx,ky),ky))),
                   #7 diagonally, descending (kx-1,ky+1), (kx-2,ky+2)
                   zip(reversed(range(kx-min(8-ky,kx),kx)),range(ky+1,8))
                  ]):
            for x,y in rg:
                if (x,y) in queens:
                    ans.append((x,y))
                    break
        
        return ans
__________________________________________________________________________________________________
