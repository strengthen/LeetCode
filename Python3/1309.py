__________________________________________________________________________________________________
sample 8 ms submission
class Solution:
    def freqAlphabets(self, s: str) -> str:
        n = len(s)
        i = 0
        ans = []
        while i < n:
            if i + 2 < n and s[i + 2] == '#':
                num = int(s[i:i+2]) - 10
                ans.append(chr(ord('j') + num))
                i += 3
            else:
                num = int(s[i]) - 1
                ans.append(chr(ord('a') + num))
                i += 1
        return ''.join(ans)
__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def freqAlphabets(self, s: str) -> str:
        res = ''
        i, n = 0, len(s)
        while i < n:
            if i + 2 < n and s[i+2] == '#':
                res += chr(int(s[i:i+2]) + 96)
                i += 3
            else:
                res += chr(int(s[i]) + 96)
                i += 1
        return res
__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def freqAlphabets(self, s: str) -> str:
        
        temp = ""
        i = len(s)-1
        while(i>=0):
            if s[i] != "#":
                temp = chr(96+int(s[i])) +temp
                i = i-1
            else:
                temp = chr(96+int(s[i-2:i])) +temp
                i = i-3
        return temp