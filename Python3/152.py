__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        def split(nums: List[int], n: int):
            """
            Split the list at elements equal to n
            """
            ret = []
            while (True):
                try:
                    find_index = nums.index(n)
                except ValueError:
                    ret.append(nums)
                    return ret
                ret.append(nums[:find_index])
                nums = nums[find_index + 1:]
                
        def prod(lst: List[int]):
            """
            Return the product of all numbers in the list.
            If the list is empty, return one.
            """
            ret = 1
            for n in lst:
                ret *= n
            return ret
                
        def maximize(lst: List[int]):
            """
            Return the maximun product possible in the list.
            Assume it doesn't include zeros.
            """
            ret = prod(lst)
            if ret > 0:
                return ret
            # If the product is negative, there must be an odd
            # number or negative numbers in the list

            # If the list is 1-element long, is already maximized
            if len(lst) == 1:
                return ret
            
            # Search the first and last negative elements
            for i, n in enumerate(lst):
                if n < 0:
                    first_negative = i
                    break
            for i, n in enumerate(reversed(lst), start=1):
                if n < 0:
                    last_negative = len(lst) - i
                    break
                    
            # Check which slice's product is larger (in magnitude)
            first_prod = prod(lst[:first_negative + 1])
            last_prod = prod(lst[last_negative:])
            return ret // max(first_prod, last_prod)
            
        splitted = split(nums, 0)
        has_zero = len(splitted) > 1
        maximized = [maximize(l) for l in splitted if len(l) > 0]
        
        if maximized:
            if has_zero:
                return max(max(maximized), 0)
            else:
                return max(maximized)
        else:
            if has_zero:
                return 0
            else:
                raise ValueError("Given empty list")
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        import sys
        gmax = nums[0]
        imax = nums[0]
        imin = nums[0]
        for j in range(1, len(nums)):
            if nums[j] < 0:
                imax,imin = imin, imax
            
            imax = max(nums[j], nums[j]*imax)
            imin = min(nums[j], nums[j]*imin)
            
            if imax > gmax:
                gmax = imax
        return gmax
__________________________________________________________________________________________________
