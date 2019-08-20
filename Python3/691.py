__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        '''
        1. each time, creat a new lev to store the target that has deleted the letters in the stickers.
        2.if new_t = '',return count
        '''
        if not target:
            return 0
        
        tmp=[]
        for s in stickers:
            dic={}
            for c in s:
                dic[c]=dic.get(c,0)+1
            tmp.append(dic)
        stickers=tmp
        lev=[target]
        count=1
        seen={target}
        while lev:
            new_lev=[]
            for t in lev:
                for s in stickers:
                    if t[0] in s:
                        new_t=t
                        for c in s:
                            new_t=new_t.replace(c,'',s[c])
                        if new_t=='':
                            return count
                        if new_t not in seen:
                            seen.add(new_t)
                            new_lev.append(new_t)
            count+=1
            lev=new_lev
        return -1
__________________________________________________________________________________________________
sample 13288 kb submission
import sys
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        m = len(stickers)
        mp = [[0]*26 for y in range(m)] 
        for i in range(m):
            for c in stickers[i]:
                mp[i][ord(c)-ord('a')] += 1    
        dp = {}
        dp[""] = 0
        
        def helper(dp, mp, target):
            if target in dp:
                return dp[target]
            n = len(mp)
            tar = [0]*26
            for c in target:
                tar[ord(c)-ord('a')] += 1  
            ans = sys.maxsize
            for i in range(n):
                if mp[i][ord(target[0])-ord('a')] == 0:
                    continue
                s = ''
                for j in range(26):
                    if tar[j] > mp[i][j]:
                        s += chr(ord('a')+j)*(tar[j] - mp[i][j]) 
                tmp = helper(dp, mp, s)
                if (tmp != -1): 
                    ans = min(ans, 1+tmp)    
            dp[target] = -1 if ans == sys.maxsize else ans
            return dp[target]
                
        return helper(dp, mp, target)
__________________________________________________________________________________________________
