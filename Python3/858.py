__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def gcd(self,n1,n2):
        return self.gcd(n2,n1%n2) if n2 != 0 else n1
    def mirrorReflection(self, p: int, q: int) -> int:
        m = self.gcd(max(p,q),min(p,q))
        n1 = p // m
        n2 = q// m
        if n2 % 2 == 0:
            return 0
        else:
            if n1 % 2 == 0:
                return 2
            else:
                return 1
__________________________________________________________________________________________________
sample 12980 kb submission
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        
        tot = q
        while tot % p != 0:
            tot += q
            
        if (tot // q) % 2 == 0:
            return 2
        else:
            return (tot // p) % 2
__________________________________________________________________________________________________
