__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num < 0:
            return '-' + self.convertToBase7(-num)
        elif num >= 7:
            return self.convertToBase7(num//7)+str(num%7)
        elif num < 7:
            return str(num)
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num < 0:
            return "-" + self.convertToBase7(-num);
        elif num == 0:
            return "0"

        res = [];
        while num > 0:
            res.append(str(num % 7))
            num //= 7

        return ''.join(res[::-1])
__________________________________________________________________________________________________
