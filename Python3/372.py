__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def powMod(self,a, b):
        if not b:
            return 1
        phalf=self.powMod(a,b>>1)
        ans= (phalf*phalf) % 1337
        return (ans*a)%1337 if b&1 else ans
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        a=a%1337
        if not b:
            return 1
        period=1
        m=(a*a)%1337
        while m!=a:
            period+=1
            m=(m*a)%1337
        v=0
        for d in b:
            v=(v*10+d)%period
        return self.powMod(a,v)
__________________________________________________________________________________________________
sample 13128 kb submission
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        

        ans = 1
        
        order = [-1] * len(b) 
        cur = a
        for i in range(len(b)-1, -1, -1):
            order[i] = a
            a = (a ** 10) % 1337
        for i in range(len(b)):
            ans = (ans * (order[i] ** b[i])) % 1337
        
        return ans
__________________________________________________________________________________________________
