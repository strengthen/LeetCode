__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def titleToNumber(self, s: str) -> int:
        if not s:
            return None
        count = 0
        res = 0
        while s:
            res += (1 + ord(s[-1]) - ord('A'))  * 26** count
            count += 1
            s = s[:-1]
        return res
__________________________________________________________________________________________________
sample 12976 kb submission
class Solution:
    def titleToNumber(self, s: str) -> int:
        if s == "":
            return 0
        return (26 * self.titleToNumber(s[:-1])) + (ord(s[-1]) - 64)
__________________________________________________________________________________________________
