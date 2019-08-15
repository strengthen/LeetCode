__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        ans = heapq.nlargest(k, nums)
        return ans[-1]
__________________________________________________________________________________________________
sample 13484 kb submission
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def partition(start, end):
            pivot = start
            while start <= end:
                while start <= end and nums[start] <= nums[pivot]:
                    start += 1
                while start <= end and nums[end] > nums[pivot]:
                    end -= 1
                if start > end: break
                nums[start], nums[end] = nums[end], nums[start]
            nums[end], nums[pivot] = nums[pivot], nums[end]    
            return end
            
        end = len(nums) - 1
        distance = len(nums) - k
        start = 0
        while start < end:
            pivot = partition(start, end)
            # print(nums)
            if pivot < distance:
                start = pivot + 1
            elif pivot > distance:
                end = pivot - 1
            else:
                # print(nums)
                return nums[pivot]
        print(nums)
        return nums[start]
__________________________________________________________________________________________________
