__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        left, right = 0, len(A) - 1
        while left < right:
            mid = (left + right) // 2
            if A[mid - 1] < A[mid] and A[mid] < A[mid + 1]:
                left = mid
            elif A[mid - 1] > A[mid] and A[mid] > A[mid + 1]:
                right = mid
            else:
                break
        return mid
__________________________________________________________________________________________________
sample 14000 kb submission
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        i = 1
        while i < len(A):
            if A[i] < A[i - 1]: 
                return i - 1
            i += 1
__________________________________________________________________________________________________
