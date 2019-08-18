__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        res += "0"*s.count('z')
        res += "1"*(s.count('o')-s.count('z')-s.count('w')-s.count('u'))
        res += "2"*s.count('w')
        res += "3"*(s.count('h') - s.count('g'))
        res += "4"*s.count('u')
        res += "5"*(s.count('f') - s.count('u'))
        res += "6"*s.count('x')
        res += "7"*(s.count('s')-s.count('x'))
        res += "8"*s.count("g")
        res += "9"*(s.count('i') - s.count('x') - s.count("g") - s.count('f') + s.count('u'))
        return res
__________________________________________________________________________________________________
sample 13128 kb submission
class Solution:
    def originalDigits(self, s: str) -> str:
        res = ""
        res += "0"*s.count('z')
        res += "1"*(s.count('o')-s.count('z')-s.count('w')-s.count('u'))
        res += "2"*s.count('w')
        res += "3"*(s.count('h') - s.count('g'))
        res += "4"*s.count('u')
        res += "5"*(s.count('f') - s.count('u'))
        res += "6"*s.count('x')
        res += "7"*(s.count('s')-s.count('x'))
        res += "8"*s.count("g")
        res += "9"*(s.count('i') - s.count('x') - s.count("g") - s.count('f') + s.count('u'))
        return res
__________________________________________________________________________________________________
