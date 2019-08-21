__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def canTransform(self, s: str, t: str) -> bool:
        if not s or not t:
            return not s and not t
        if len(s) != len(t):
            return False
        
        n = len(s)
        i = j = 0
        
        while i < n or j < n:
            while i < n and s[i] == 'X':
                i += 1
            while j < n and t[j] == 'X':
                j += 1
            
            if i >= n or j >= n:
                return i >= n and j >= n
            
            if s[i] != t[j]: return False
            if s[i] == 'L' and i < j: return False
            if s[i] == 'R' and i > j: return False
            
            i += 1
            j += 1
        
        return i >= n and j >= n
__________________________________________________________________________________________________
sample 13172 kb submission
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        if start.replace('X', '') != end.replace('X', ''):
            return False
        t = 0
        for i in range(0, len(start)):
            if start[i] == 'L':
                while t < len(end) and end[t] != 'L':
                    t += 1
                if i < t:return False
                t += 1
        t = 0
        for i in range(0, len(start)):
            if start[i] == 'R':
                while t < len(end) and end[t] != 'R':
                    t += 1
                if i > t:return False
                t += 1
        return True
__________________________________________________________________________________________________
