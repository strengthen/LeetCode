__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        def _canPartitionKSubsets(group_sums):
            if len(nums) == 0:
                return True

            num = nums.pop()
            
            for i in range(k):
                if group_sums[i] + num <= target:
                    group_sums[i] += num
                    
                    if _canPartitionKSubsets(group_sums):
                        return True
                    
                    group_sums[i] -= num
                    
                if group_sums[i] == 0:
                    break

            nums.append(num)

            return False

        target, rem = divmod(sum(nums), k)
        
        if rem:
            return False

        nums.sort()
        
        if nums[-1] > target:
            return False

        while nums and nums[-1] == target:
            nums.pop()
            k -= 1

        group_sums = [0] * k

        return _canPartitionKSubsets(group_sums)
__________________________________________________________________________________________________
sample 12904 kb submission
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        target, rem = divmod(sum(nums), k)
        if rem: return False

        def search(groups):
            if not nums: return True
            v = nums.pop()
            for i, group in enumerate(groups):
                if group + v <= target:
                    groups[i] += v
                    if search(groups): return True
                    groups[i] -= v
                if not group: break
            nums.append(v)
            return False

        nums.sort()
        if nums[-1] > target: return False
        while nums and nums[-1] == target:
            nums.pop()
            k -= 1

        return search([0] * k)        
__________________________________________________________________________________________________
