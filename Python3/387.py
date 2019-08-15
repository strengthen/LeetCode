__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def firstUniqChar(self, s: str) -> int:
        uniq = []
        first = len(s)
        for letter in "abcdefghijklmnopqrstuvwxyz":
            pos = s.find(letter)
            rep = s.rfind(letter)
            if pos == rep and pos >= 0:
                if pos < first:
                    first = pos
        return first if first < len(s) else -1
__________________________________________________________________________________________________
sample 13044 kb submission
class Solution:
    def firstUniqChar(self, s: str) -> int:
        from collections import Counter
        c = Counter(s)

        for i in range(len(s)):
            if c[s[i]] == 1:
                return i
            
        return -1
__________________________________________________________________________________________________
