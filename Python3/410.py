__________________________________________________________________________________________________
sample 24 ms submission
class Solution:    
    def splitArray(self, nums: List[int], m: int) -> int:
        assert nums
        def is_valid(target, nums, m):
            s, c = 0, 1
            for x in nums:
                s += x
                if s > target:
                    s = x
                    c += 1
                    if c > m:
                        return False
                # print(s, c, x, m)
            return True
        low = max(nums)
        high = sum(nums)
        while low != high:
            mid = (low + high) // 2
            if is_valid(mid, nums, m):
                high = mid
            else:
                low = mid + 1
        # a = [(x, is_valid(x, nums, m)) for x in range(max(nums), sum(nums)+1)]
        # print(a)
        return low
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l = max(nums)
        r = sum(nums) + 1
        
        while l < r:
            mid = l + (r - l) // 2
            
            cnt = 0
            groups = 0
            for n in nums:
                cnt += n
                if cnt > mid:
                    groups += 1
                    cnt = n
            
            if cnt > 0:
                groups += 1
            
            if groups <= m:
                r = mid
            else:
                l = mid + 1
        
        return l
__________________________________________________________________________________________________
