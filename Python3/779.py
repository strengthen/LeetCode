__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        num = 0
        K -= 1
        for i in range(N-1):
            if K%2 == 1:
                num = 1-num
            K //= 2
        
        return num
__________________________________________________________________________________________________
sample 13060 kb submission
class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N == 1:
            if K == 1:
                return 0
            else:
                return 1
        half = 2 ** (N-1)
        if K <= half:
            return self.kthGrammar(N-1, K)
        else:
            return (self.kthGrammar(N-1, K-half) + 1) % 2
__________________________________________________________________________________________________
