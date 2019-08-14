__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def rotate(self, n: List[int], k: int) -> None:
    	L, a, i, c, j = len(n), n[0], 0, 0, 0
    	k = k % L
    	if L in [0,1] or k == 0: return n
    	while c < L:
    		I = (i+k)%L
    		a, n[I], i = n[I], a, I
    		c += 1
    		if i == j:
    			j += 1
    			a = n[j]
    			i = j
    	return n
__________________________________________________________________________________________________
sample 13252 kb submission
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        
        start = 0
        count = 0
        
        while count < n:
            current = start
            prev = nums[current]
            
            next = (current + k) % n
            temp = nums[next]
            nums[next], prev = prev, nums[next]
            current = next
            prev = temp
            count += 1
            
            
            while start != current:
                next = (current + k) % n
                temp = nums[next]
                nums[next], prev = prev, nums[next]
                current = next
                prev = temp
                
                count += 1
                
            start += 1
__________________________________________________________________________________________________
