__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def tribonacci(self, n: int) -> int:
        
        if n==0:
            return 0
        
        if n==1 or n==2:
            return 1
    
        a0=0
        a1=1
        a2=1
        
        while n-2>0:
            temp = a0+a1+a2
            a0=a1
            a1=a2
            a2=temp
            n-=1
        
        return a2
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def tribonacci(self, n: int) -> int:
        #if n == 0: return 0
        #elif n == 1 or n == 2: return 1
        #else: return self.tribonacci(n-1) + self.tribonacci(n-2) + self.tribonacci(n-3) 
        seq = [0, 1, 1]
        for i in range(n-2):
            seq.append(seq[-1]+seq[-2]+seq[-3])
        return seq[n]
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1
        v0, v1, v2 = 0, 1, 1
        for i in range(3, n+1):
            v0, v1, v2 = v1, v2, v0+v1+v2
        return v2