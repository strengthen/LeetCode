__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        a = self.str2int(num1)
        b = self.str2int(num2)
        return str(a + b)
    def str2int(self, num):
        return int(num)
__________________________________________________________________________________________________
sample 13012 kb submission
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        return str(int(num1)+int(num2))
__________________________________________________________________________________________________
