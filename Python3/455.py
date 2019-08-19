__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s.sort()#candy
        g.sort()#kid        
        count=0        
        j=0#kid
        for candy in s:
            if j>len(g)-1:
                return count
            if g[j] <= candy:
                count+=1
                j+=1
                                      
        return count
__________________________________________________________________________________________________
sample 14260 kb submission
#
# @lc app=leetcode id=455 lang=python3
#
# [455] Assign Cookies
#
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        satis = 0
        g.sort()
        s.sort()
        for c in g:
            i = 0
            while i < len(s):
                if c <= s[i]:
                    del s[i]
                    satis += 1
                    break
                i += 1
        return satis
__________________________________________________________________________________________________
