__________________________________________________________________________________________________
sample 88 ms submission
from collections import defaultdict
class Solution:
    def containsNearbyDuplicate(self, nums, k):
        if len(nums) == len(set(nums)) or not k:
            return False
        memo = defaultdict(list)
        for i, num in enumerate(nums):
            memo[num].append(i)
        diffs = []
        for num, inds in memo.items():
            cur = inds[0]
            for i in inds[1:]:
                diffs.append(i - cur)
                cur += i
            if diffs and min(diffs) > k:
                return False
        return True
__________________________________________________________________________________________________
sample 17628 kb submission
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums) == len(set(nums)):
            return False
        record = {}
        for key, value in enumerate(nums):
            if value in record.keys() and key-record[value] <= k:
                return True
            else:
                record[value] = key
        return False
__________________________________________________________________________________________________
