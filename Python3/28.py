__________________________________________________________________________________________________
32ms
class Solution:
    def strStr(self, haystack: 'str', needle: 'str') -> 'int':
        a=haystack.find(needle)
        return a
__________________________________________________________________________________________________
36ms
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1
__________________________________________________________________________________________________
40ms
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle)==0 :
            return 0
        if len(needle) > len(haystack):
            return -1
        for i in range(len(haystack)):
            if i+len(needle) <=len(haystack) and haystack[i:i+len(needle)]==needle:
                return i
        return -1
__________________________________________________________________________________________________
12244 kb 
class Solution:
    def strStr(self, haystack: 'str', needle: 'str') -> 'int':
        try:
            return haystack.index(needle)
        except:
            return -1
__________________________________________________________________________________________________
12296 kb
class Solution:
    def strStr(self, haystack: 'str', needle: 'str') -> 'int':        
        
        return (haystack.find(needle))
__________________________________________________________________________________________________
