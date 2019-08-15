__________________________________________________________________________________________________
sample 72 ms submission
from collections import deque
class Solution:
    def canCross(self, s: List[int]) -> bool:
        stones = set(s)
        step = 1
        for i in range(len(s) - 1):
            if s[i + 1] - s[i] > step: return False
            step += 1
        def helper(start, end, step):
            if start == end: return True
            if start not in stones: return False
            if helper(start + step + 1, end, step + 1): return True
            if helper(start + step, end, step): return True
            if step > 1 and helper(start + step - 1, end, step - 1): return True
            return False
        return helper(1, s[-1], 1)
__________________________________________________________________________________________________
sample 13376 kb submission
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if (len(stones) - 1 > stones[-1]
                or stones[-1] > (len(stones) - 1)*(len(stones))/2):
            return False
        
        last_stone = stones[-1] # keep the value of the last stone
        stones = set(stones)     # convert the stones positions into set, to have O(1) check using "in"
        jumps_stack = [(1, 1)] # we are at the second stone with k = 1
        
        while jumps_stack: 
            current_stone = jumps_stack.pop() # pop the last element from stack
            pos = current_stone[0]
            k = current_stone[1]
            for dk in [-1,0,1]: 
                candidate_stone = pos + k + dk
                if candidate_stone in stones:
                    if pos + k + dk == last_stone: # if we have reached the last stone
                        return True
                    if k + dk > 0:  # avoid situations when k = 1 and dk = -1, since sum is 0
                        jumps_stack.append((candidate_stone, k + dk))
        return False
__________________________________________________________________________________________________
