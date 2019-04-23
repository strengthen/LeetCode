__________________________________________________________________________________________________
32ms
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        if size <= 1 or s == s[::-1]:
            return s
        
        start = 0
        maxlen = 1
        for idx in range(1, size):
            add2 = s[idx - maxlen - 1: idx + 1]
            if idx - maxlen - 1 >= 0 and add2 == add2[::-1]:
                start = idx - maxlen - 1
                maxlen += 2
                continue
            add1 = s[idx - maxlen : idx + 1]
            if add1 == add1[::-1]:
                start = idx - maxlen
                maxlen += 1
        
        return s[start:(start + maxlen)]
__________________________________________________________________________________________________
40ms
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == s[::-1]:
            return s
        maxLen = 1
        start = 0
        for i in range(1, len(s)):
            poss_start = i - maxLen
            if poss_start >= 0 and s[poss_start:i+1] == s[poss_start:i+1][::-1]:
                maxLen += 1
                start = poss_start
            if poss_start >= 1 and s[poss_start-1:i+1] == s[poss_start-1:i+1][::-1]:
                maxLen += 2
                start = poss_start-1
        return s[start:start+maxLen]
__________________________________________________________________________________________________
48ms
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        start, max_length = 0, 0
        
        for i in range(length):
            l1, l2 = i - max_length - 1, i - max_length
            if l1 >= 0 and s[l1: i+1] == s[l1: i+1][::-1]:
                start = l1
                max_length += 2
            elif l2 >= 0 and s[l2: i+1] == s[l2: i+1][::-1]:
                start = l2
                max_length += 1
        return s[start: start+max_length]
__________________________________________________________________________________________________
10556 kb
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        bestr = ''
        for i in range(len(s) - 1, -1, -1):
            j= 0
            while i+j<=len(s)-1 and i-j>=0:
                if s[i+j]!=s[i-j]:
                    break
                else:
                    bestr = s[i-j:i+j+1] if len(bestr)<2*j+1 else bestr
                    j+=1
            j= 0
            while i+j+1<=len(s)-1 and i-j>=0:
                if s[i+j+1]!=s[i-j]:
                    break
                else:
                    bestr = s[i-j:i+j+2] if len(bestr)<2*j+2 else bestr
                    j+=1
        return bestr
__________________________________________________________________________________________________
10564 kb
class Solution(object):
    def longestPalindrome(self,s):
        if len(s)<2:return s
        i,ans = 0,""
        while i<len(s):
            j,k = i+1,i-1
            while j<len(s) and s[j]==s[i]:
                j += 1
            i=j
            while k>=0 and j<len(s) and s[k]==s[j]:
                k,j=k-1,j+1
            if j-k-1>=len(ans):
                ans = s[k+1:j]
        return ans
__________________________________________________________________________________________________
