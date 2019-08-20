__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
    	L, M, s = len(nums), 0, 0
    	if L == 0: return 0
    	for i in range(L-1):
    		s += 1
    		if nums[i+1] <= nums[i]:
    			if s > M: M = s
    			s = 0
    	return max(M,s+1)
__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:

        # Base Case 
        if nums == []: return 0
        
        curr = 1
        max_seq = -2**31
        prev = nums[0]

        for n in nums: 
            if n > prev: 
                curr += 1
            elif n <= prev: 
                curr = 1
            max_seq = max(curr, max_seq)
            prev = n
            
        return max_seq
__________________________________________________________________________________________________
