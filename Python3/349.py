__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return set(nums1).intersection(set(nums2))
__________________________________________________________________________________________________
sample 13056 kb submission
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        nums1 = set(nums1)
        nums2 = set(nums2)
        list3 = [val for val in nums1 if val in nums2]
        return list3
__________________________________________________________________________________________________
