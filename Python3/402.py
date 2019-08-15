__________________________________________________________________________________________________
sample 32 ms submission
#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        out = []
        for c in num:
            while k > 0 and out and out[-1] > c:
                out.pop()
                k -= 1
            out.append(c)
        return ''.join(out[:-k or None]).lstrip('0') or '0'
__________________________________________________________________________________________________
sample 13060 kb submission
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k >= len(num):
            return '0'
        
        changed = False
        while k > 0:
            for i in range(len(num) - 1):
                if num[i] > num[i+1]:
                    num = num[:i] + num[i+1:]
                    changed = True
                    break
                    
            if not changed:
                num = num[:-1]
            k -= 1
            changed = False
            
        i = 0
        while i < len(num) - 1 and num[i] == '0':
            i += 1
            
        return num[i:]
__________________________________________________________________________________________________
