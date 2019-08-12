__________________________________________________________________________________________________
sample 32 ms submission
import collections

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if sorted(s1) != sorted(s2):
            return False

        def dfs(a,b):
            n = len(a)
            if n <= 2:
                return True

            front_cnt = collections.defaultdict(int)
            back_cnt = collections.defaultdict(int)
            for i in range(n - 1):
                x, y, z = a[i], b[i],  b[n - 1 - i]
                
                front_cnt[x] += 1
                if front_cnt[x] == 0: del front_cnt[x]
                front_cnt[y] -= 1
                if front_cnt[y] == 0: del front_cnt[y]
                if len(front_cnt) == 0:
                    if dfs(a[:i + 1], b[:i + 1]) and dfs(a[i + 1:], b[i + 1:]):
                        return True
                
                back_cnt[x] += 1
                if back_cnt[x] == 0: del back_cnt[x]
                back_cnt[z] -= 1
                if back_cnt[z] == 0: del back_cnt[z]
                if len(back_cnt) == 0:
                    if dfs(a[:i + 1], b[n - i - 1:]) and dfs(a[i + 1:], b[:n - i - 1]):
                        return True
            return False

        return dfs(s1, s2)        
__________________________________________________________________________________________________
sample 13180 kb submission
class Solution:
    def isScramble(self, s1, s2):
        if( s1==s2):return True
        if sorted(s1)!=sorted(s2):return False
        
        for i in range(1,len(s1)):
      
            a=self.isScramble(s1[:i],s2[:i])
            b=self.isScramble(s1[i:],s2[i:])
            if a and b:return True
            a=self.isScramble(s1[i:],s2[:-i])
            b=self.isScramble(s1[:i],s2[-i:])
     
            if a and b:return True
        return False
__________________________________________________________________________________________________
