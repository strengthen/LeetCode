__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return '0'
        mask = [1 << i for i in range(1, 33, 2)]
        for neg in mask:
            if N & neg:
                N += 2 * neg
        return bin(N)[2:]
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return "0"
        if N == 1:
            return '1'
        if N % 2 == 0:
            return self.baseNeg2(N/(-2)) + '0'
        else:
            return self.baseNeg2((N-1)/(-2)) + '1'
__________________________________________________________________________________________________
