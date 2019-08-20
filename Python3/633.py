__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i = 2
        while i * i < c:
            counter = 0
            while 0 == c % i:
                if 3 == i % 4:
                    counter += 1
                else:
                    pass
                c //= i
            if 0 != counter and 0 != counter % 2:
                return False
            else:
                i += 1
        return 3 != c % 4
__________________________________________________________________________________________________
sample 12888 kb submission
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0:
            return True
        import math
        for i in range(c):
            if i*i <= c:
                tmp = math.sqrt(c-i*i)
                if tmp == int(tmp):
                    return True
            else:
                break
        return False
__________________________________________________________________________________________________
