__________________________________________________________________________________________________
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) == len(str2):
            return str1 if str1==str2 else ''
        else:
            if len(str1) < len(str2):
                str1,str2 = str2,str1
            if str1[:len(str2)] == str2:
                return self.gcdOfStrings(str1[len(str2):],str2)
            else:
                return ''
__________________________________________________________________________________________________

__________________________________________________________________________________________________
