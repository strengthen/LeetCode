__________________________________________________________________________________________________
sample 108 ms submission
class Solution(object):
    def balancedString(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        #O(n) algorithm 
        n = len(s) / 4
        count = {'Q' : 0, 'W' : 0, 'E' : 0, 'R' : 0}
        
        for char in s:
            if count[char] < n:
                count[char] += 1
            else:
                break
        
        rtype = sum(count.values())
        current = rtype # current record the maximum string that does not exceed bound
        i = rtype - 1
        
        if rtype == len(s):
            return 0
        
        for char in reversed(s):
            if count[char] < n:
                count[char] += 1
                current += 1
                rtype = max(rtype, current)
            else:
                while (s[i] != char and i >= 0): 
                    count[s[i]] -= 1
                    i = i - 1
                    current = current - 1
                    
                if (i == -1):
                    break
                    
                i = i - 1
                    
        return (len(s) - rtype)
__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def balancedString(self, s: str) -> int:
        n=len(s)//4
        q={'Q':0,'W':0,'E':0,'R':0}
        expected=len(s)//4
        for i in range(len(s)):
            if q[s[i]]<n:
                q[s[i]]+=1
            else:
                break
        rtype=sum(q.values())
        current=rtype
        i=rtype-1
        if rtype ==len(s):
            return 0
        for char in reversed(s):
            if q[char]<n:
                q[char]+=1
                current+=1
                rtype=max(rtype, current)
            else:
                while s[i]!=char and i>=0:
                    q[s[i]]-=1
                    i-=1
                    current=current-1
                if i==-1:
                    break
                
                i-=1
        return len(s)-rtype
__________________________________________________________________________________________________
