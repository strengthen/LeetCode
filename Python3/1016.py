__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def queryString(self, S: str, N: int) -> bool:
        return all(bin(i)[2:] in S for i in range(N, N // 2, -1))
__________________________________________________________________________________________________
sample 12920 kb submission
class Solution:
    def queryString(self, S: str, N: int) -> bool:
        start = 10 ** (len(str(N)) - 1)
        for x in range(1, N + 1):
            if format(x, 'b') not in S:
                return False
        return True
__________________________________________________________________________________________________
