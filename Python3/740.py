__________________________________________________________________________________________________
sample 44 ms submission
from collections import defaultdict
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if len(nums) <= 0:
            return 0
        nums_dict = defaultdict(int)
        for n in nums:
            nums_dict[n] += 1
        nums_list = list(nums_dict.keys())
        nums_list.sort()
        ret = [0 for i in nums_list]
        for idx, n in enumerate(nums_list):
            earn_curr = n * nums_dict[n]
            if idx >= 1 and n - nums_list[idx -1] > 1:
                ret[idx] = ret[idx - 1] + earn_curr
            elif idx >= 2:
                ret[idx] = max(ret[idx - 2] + earn_curr, ret[idx - 1])
            else:
                if idx >= 1:
                    ret[idx] = max( earn_curr, ret[idx - 1])
                else:
                    ret[idx] = earn_curr
        print(ret)
        return max(ret)
__________________________________________________________________________________________________
sample 13240 kb submission
from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        freq = Counter(nums)
        take, no_take = 0, 0
        for i in range(min(nums), max(nums)+1):
            take, no_take = no_take + freq[i]*i, max(take, no_take)
        return max(take, no_take)
__________________________________________________________________________________________________
