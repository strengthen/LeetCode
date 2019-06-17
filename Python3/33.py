__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums)==0:return -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid]==target:
                return mid
            if nums[mid]<nums[left]:
                if target > nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid -1
            else:
                if target < nums[mid] and target >= nums[left]:
                    right = mid -1
                else:
                    left = mid + 1
        return -1
__________________________________________________________________________________________________
sample 12800 kb submission
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Check whether the input array is None or empty
        if not nums:
            return -1
        # Assumption: nums is sorted and no duplicate exists in the array

        # Binary search
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:  # Found it
                return mid
            if nums[mid] < nums[right]:  # [left, mid] itself is rotated sorted and [mid, right] is sorted
                if nums[mid] < target <= nums[right]:
                    # The target must lie in the right half.
                    left = mid + 1
                else:
                    # The target must lie in the left half.
                    right = mid - 1
            else:  # [left, mid] is sorted and [mid, right] itself is rotated sorted.
                if nums[left] <= target < nums[mid]:
                    # The target must lie in the left half.
                    right = mid - 1
                else:
                    # The target must lie in the right half.
                    left = mid + 1
        # Not found
        return -1
        # Time: O(log n)
__________________________________________________________________________________________________
