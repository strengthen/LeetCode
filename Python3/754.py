__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def reachNumber(self, target: int) -> int:
        # (n+1)*n/2....t
        t=abs(target)
        n=math.floor((t*2)**0.5)
        while True:
            diff=(n+1)*n/2-t
            if diff>=0:
                if diff%2==0:
                    return int(n)
            n+=1
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        n = math.sqrt(target * 2 + 1 / 4) - 1 / 2
        if n == int(n):
            return int(n)
        else:
            k = int(n) + 1
            while (int((k + k * k) / 2) - target) % 2 != 0:
                k = k + 1
            return k
__________________________________________________________________________________________________
