__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def convertToTitle(self, n: int) -> str:
        capitals = [chr(x) for x in range(ord('A'), ord('Z')+1)]
        res = []
        while n > 0:
            res.append(capitals[(n-1) % 26])
            n = (n-1) // 26
        res.reverse()
        return ''.join(res)
__________________________________________________________________________________________________
sample 12988 kb submission
class Solution:
    def convertToTitle(self, n: int) -> str:
        count = 0
        d = collections.defaultdict()
        for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            d[count] = i
            count += 1
        res = ''
        n -= 1
        while n>=0:
            res = d[(n)%26] + res
            n//=26
            n-=1
        return res
__________________________________________________________________________________________________
