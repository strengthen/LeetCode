__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        string = bin(x^y)
        result = 0
        for i in string:
            if i == '1':
                result += 1
        return result
__________________________________________________________________________________________________
sample 12992 kb submission
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count('1')
__________________________________________________________________________________________________
