__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def toLowerCase(self, st: str) -> str:
        s = ''
        for i in st:
            if 'A' <=  i <= 'Z':
                s +=  chr(ord(i)+32)
            else:
                s+=i
        return s
__________________________________________________________________________________________________
sample 12936 kb submission
class Solution:
    def toLowerCase(self, str_input: str) -> str:
        str_aux = str()
        for i,char in enumerate(str_input):
            if char.isupper():
                str_aux+=char.lower()
            else:
                str_aux+=char;
        return str_aux;
__________________________________________________________________________________________________
