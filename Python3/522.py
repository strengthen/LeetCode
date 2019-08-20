__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def findLUSlength(self, strs):
        
        def subseq(src, sub):
            i = 0
            n = len(sub)
            for ch in src:
                if i < n and sub[i] == ch:
                    i += 1
            return i == len(sub)
            
        strs.sort(key=len, reverse=True)

        for i, sub in enumerate(strs):
            for j, src in enumerate(strs):
                if i == j or len(src) < len(sub):
                    continue
                
                if True == subseq(src, sub): # possible not continuous
                    break
            else:   # mean this stubstr is longest and no sub
                return len(sub)
        return -1
__________________________________________________________________________________________________
sample 32 ms submission
class Solution(object):
    
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def substring_of(s1, s2):
            # s2 is longer.
            i1 = i2 = 0
            while i1 < len(s1) and i2 < len(s2):
                if s2[i2] != s1[i1]:
                    i2 += 1
                else:
                    i1 += 1
                    i2 += 1
            return i1==len(s1)
        
        unique_set = set()
        removed_set = set()
        for s in strs:
            if s in unique_set:
                unique_set.remove(s)
                removed_set.add(s)
            elif s not in removed_set:
                unique_set.add(s)

        for s in sorted(unique_set, key=len, reverse=True):
            for s2 in removed_set:
                if len(s2)>len(s) and substring_of(s, s2):
                    break
            else:
                return len(s)
        return -1
__________________________________________________________________________________________________
