__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        lookup = {}
        for n in nums1:
            lookup[n] = lookup.get(n, 0) + 1
        ret = []
        for n in nums2:
            if n in lookup:
                count = lookup[n]
                lookup[n] -= 1
            else:
                count = 0
            if count > 0:
                ret.append(n)
        return ret            
__________________________________________________________________________________________________
sample 13004 kb submission
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        i1 = i2 = 0
        
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        i2count = dict()
        for i in nums1:
            i2count[i] = i2count.get(i, 0) + 1
        
        for i in nums2:
            if i in i2count:
                result.append(i)
                i2count[i] -= 1
                if i2count[i] == 0:
                    del i2count[i]
        
        return result
__________________________________________________________________________________________________
