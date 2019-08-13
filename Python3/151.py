__________________________________________________________________________________________________
sample 20 ms submission
import sys

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        
        left = 0
        right = len(words)-1
        
        while left < right:
            words[left], words[right] = words[right], words[left]
            left += 1
            right -= 1

        return " ".join(words)
__________________________________________________________________________________________________
sample 13284 kb submission
#
# @lc app=leetcode id=151 lang=python3
#
# [151] Reverse Words in a String
#
class Solution:
    def reverseWords(self, s: str) -> str:
        res = []
        s += ' '
        temp = ''
        for c in s:
            if c == ' ':
                if temp:
                    res.insert(0, temp)
                    temp = ''
            else:
                temp+=c
        return ' '.join(res)

__________________________________________________________________________________________________
