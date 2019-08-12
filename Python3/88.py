__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = m - 1, n - 1
        slot_index = m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[slot_index] = nums1[i]
                i -= 1
            else:
                nums1[slot_index] = nums2[j]
                j -= 1
            slot_index -= 1
        
        while j >= 0:
            nums1[slot_index] = nums2[j]
            slot_index -= 1
            j -= 1
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        j, k = 0, 0
        index = 0
        temp = 0
        while index < len(nums1):        
            if n == 0:
                break
            if nums1[index] <= nums2[k] and j != m:
                j += 1
            elif j == m:
                nums1[index] = nums2[k]
                k+=1
            else:
                temp = nums2[k]
                for i in range((len(nums1)-1), index, -1):
                    nums1[i] = nums1[i-1]
                nums1[index] = nums2[k]
                k += 1
                if k == n:
                    break
            index += 1
__________________________________________________________________________________________________
