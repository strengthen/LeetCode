__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        if arrLen==1: return 1
        a,m,k=[1,0],10**9+7,min(steps//2,arrLen-1)
        for _ in range(k):
            b=[0]*(len(a)+1)
            b[-2]=a[-2]
            for i in range(len(a)-1): b[i]=(a[i-1]+a[i]+a[i+1])%m
            a=b
        for _ in range(steps-2*k): a=[(a[i-1]+a[i]+a[i+1])%m for i in range(len(a)-1)]+[0]
        for _ in range(k): a=[(a[i-1]+a[i]+a[i+1])%m for i in range(len(a)-2)]+[0]
        return a[0]
__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        if arrLen==1: return 1
        a,m,k=[1,0],10**9+7,min(steps//2,arrLen-1)
        for _ in range(k):
            b=[0]*(len(a)+1)
            b[-2]=a[-2]
            for i in range(len(a)-1): b[i]=(a[i-1]+a[i]+a[i+1])%m
            a=b
        for _ in range(steps-2*k): a=[(a[i-1]+a[i]+a[i+1])%m for i in range(len(a)-1)]+[0]
        for _ in range(k): a=[(a[i-1]+a[i]+a[i+1])%m for i in range(len(a)-2)]+[0]
        return a[0]
__________________________________________________________________________________________________
