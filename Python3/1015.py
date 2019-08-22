__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k%2==0 or k%5==0:
            return -1
        n=0
        for x in range(1,k+1):
            n=(n*10+1)%k
            if n==0:
                return x
        return -1
__________________________________________________________________________________________________
sample 13128 kb submission
class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0:
            return -1
        
        K_Max = 10 ** 5 + 1
        index = 1
        num = 1
        if 1 % K == 0:
            return 1
        while index < K_Max:
            num = ((num * (10 % K)) % K + 1) % K
            index += 1
            if num == 0:
                return index
        return -1
__________________________________________________________________________________________________
