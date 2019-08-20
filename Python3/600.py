__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def findIntegers(self, num: int) -> int:
        x, y, res = 1, 2, 0
        num += 1
        while num:
            if num & 1 and num & 2: res = 0
            res += x * (num & 1)
            num >>= 1
            x, y = y, x + y
        return res 
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def findIntegers(self, num: int) -> int:
        f = [0] * 32
        f[0] = 1
        f[1] = 2
        for i in range(2, 32):
            f[i] = f[i - 1] + f[i - 2]
        i, sm , prevBit = 30, 0, 0
        while i >= 0 :
            if num & (1 << i):
                sm += f[i]
                if prevBit:
                    sm -= 1
                    break
                prevBit = 1
            else:
                prevBit = 0
            i -= 1
        return sm + 1
__________________________________________________________________________________________________
