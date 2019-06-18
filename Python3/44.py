__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        pos_s = -1
        pos_p = -1
        last_s = -1
        last_p = -1
        
        # Find first *
        for i in range(len(p)):
            if p[i] == '*':
                pos_s = i
                pos_p = i
                break
            elif i >= len(s):
                return False
            elif p[i] != '?' and s[i] != p[i]:
                return False
            
        if pos_p == -1:
            return len(s) == len(p)
        
        # Find last *
        for i in range(1, len(p) + 1):
            if p[len(p) - i] == '*':
                last_s = len(s) - i
                last_p = len(p) - i
                break
            elif len(s) - i < pos_s:
                return False
            elif p[len(p) - i] != '?' and s[len(s) - i] != p[len(p) - i]:
                return False
        
        if pos_p == last_p:
            return True
        
        pos_p += 1
        index_s = pos_s
        index_p = pos_p
        while index_p < last_p + 1:
            if p[index_p] == '*':
                pos_s = index_s
                index_p += 1
                pos_p = index_p
            elif index_s > last_s:
                return False
            elif p[index_p] == '?' or s[index_s] == p[index_p]:
                index_s += 1
                index_p += 1
            else:
                pos_s += 1
                index_s = pos_s
                index_p = pos_p
        
        return True
__________________________________________________________________________________________________
sample 12944 kb submission
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = 0
        j = 0
        ii = 0
        star = None
        while i < len(s):
            if j < len(p) and (p[j] == '?' or s[i] == p[j]):
                i+=1
                j+=1
                continue
                
            elif j < len(p) and p[j] == '*':
                star = j
                j += 1
                ii = i  
                continue
                
            if star is not None:
                j = star+1
                ii +=1
                i = ii
                continue
            return False
        
        while j < len(p) and p[j] == '*':
            j+=1
        
        return j == len(p)
__________________________________________________________________________________________________
