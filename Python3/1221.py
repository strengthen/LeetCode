__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = 0 
        count_left = 0
        count_right = 0
        for c in s:
            if(c == 'L'): count_left += 1
            if(c == 'R'): count_right += 1
            if(count_left == count_right):
                count += 1
                count_left, count_right = 0,0
        return count
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = bal = 0
        for c in s:
            bal += 1 if c == 'L' else -1
            if bal == 0: res += 1
        return res
__________________________________________________________________________________________________
