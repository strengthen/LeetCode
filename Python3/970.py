__________________________________________________________________________________________________
sample 28 ms submission

class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        res = []
        from math import ceil, log
        
        u_i, u_j = 0, 0
        if x > 1:
            u_i = ceil(log(bound - 1) / log(x))
        if y > 1:
            u_j = ceil(log(bound - 1) / log(y))
        
        for i in range(u_i + 1):
            for j in range(u_j + 1):
                tmp = x ** i + y ** j
                if tmp <= bound:
                    res.append(tmp)
        
        return list(set(res))        
__________________________________________________________________________________________________
sample 13056 kb submission
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        return list({x ** i + y ** j for i in range(20) for j in range(20) if x**i + y**j <= bound})
__________________________________________________________________________________________________
