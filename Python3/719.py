__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        """2019-08-12 
        sort nums, compute the search space [0, r]
        for d in search space, compute count(d): # of distances that <= d.
        use binary search to find the smallest d s.t. count(d) >= k is the result
        """
        nums.sort()     # O(NlogN)

        def count(guess):
            #Is there k or more pairs with distance <= guess?
            count = left = 0
            for right, x in enumerate(nums):
                while x - nums[left] > guess:
                    left += 1
                count += right - left
            return count
    
        
        right = nums[-1] - nums[0]  # search range, right for binary search
        left = 0                    # left for binary search
        
        # find the first d such that count(d) >= k
        while (left < right):
            d = left + (right-left)//2 
            if count(d) < k:
                left = d+1
            else:
                right = d
        
        return left
__________________________________________________________________________________________________
sample 13512 kb submission
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def countPairsLTE(val):
            res, i = 0, 0
            for j in range(1, len(nums)):
                while i < j and nums[j] - nums[i] > val: i += 1
                if nums[j] - nums[i] <= val: res += j - i
            return res
        nums.sort()
        low = min(nums[i+1] - nums[i] for i in range(len(nums) - 1))
        high = nums[-1] - nums[0]
        while low < high:
            mid = (low + high) // 2
            if countPairsLTE(mid) < k: low = mid + 1
            else: high = mid
        return low
__________________________________________________________________________________________________
