__________________________________________________________________________________________________
sample 104 ms submission
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        freq_sums = {0:1}
        sum = 0
        for num in nums:
            sum += num
            if sum - k in freq_sums:
                count += freq_sums[sum-k]
            
            if sum not in freq_sums:
                freq_sums[sum] = 1
            else:
                freq_sums[sum] += 1
            
        return count
__________________________________________________________________________________________________
sample 14944 kb submission
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = collections.Counter()
        cnt[0] = 1
        for i in range(1, len(nums)):
            nums[i]+= nums[i-1]
        res = 0
        for i in range(len(nums)):
            res+= cnt[nums[i]-k]
            cnt[nums[i]]+=1
        return res
__________________________________________________________________________________________________
