__________________________________________________________________________________________________
sample 32 ms submission
#
# @lc app=leetcode id=132 lang=python3
#
# [132] Palindrome Partitioning II
#
class Solution:
    def minCut(self, s: str) -> int:
        
        if s == s[::-1]: return 0
        for i in range(1, len(s)):
            if s[:i] == s[:i][::-1] and s[i:] == s[i:][::-1]:
                return 1
        # algorithm
        cut = [x for x in range(-1,len(s))]  # cut numbers in worst case (no palindrome)
        for i in range(len(s)):
            r1, r2 = 0, 0
            # use i as origin, and gradually enlarge radius if a palindrome exists
            # odd palindrome
            while i-r1 >= 0 and i+r1 < len(s) and s[i-r1] == s[i+r1]:
                cut[i+r1+1] = min(cut[i+r1+1], cut[i-r1]+1)
                r1 += 1
            # even palindrome
            while i-r2 >= 0 and i+r2+1 < len(s) and s[i-r2] == s[i+r2+1]:
                cut[i+r2+2] = min(cut[i+r2+2], cut[i-r2]+1)
                r2 += 1
        print(cut)
        return cut[-1]
__________________________________________________________________________________________________
sample 13192 kb submission
class Solution:
    def minCut(self, s: str) -> int:      
        #O(n^2)+O(n^2)
        if len(s)==1:
            return 0
        dp=[float('inf')]*len(s)
        dp[0]=0
        dp[1]=0 if s[0]==s[1] else 1
        for i in range(2,len(s)):
            if self.isPalin(s[0:i+1]):
                dp[i]=0
            else:
                for k in range(0,i):
                    if self.isPalin(s[k+1:i+1]):
                        dp[i]=min(dp[i],dp[k]+1)
        # print(dp)
        return dp[-1]
    def isPalin(self,s):
        return s==s[::-1]
__________________________________________________________________________________________________
