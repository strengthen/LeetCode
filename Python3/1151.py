__________________________________________________________________________________________________
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        count_one = sum(data)
        if count_one == 0:
            return 0

        n = len(data)
        cur = sum(data[:count_one])
        ans = cur
        for i in range(count_one, n):
            cur += data[i] - data[i - count_one]
            ans = max(ans, cur)

        return count_one - ans
__________________________________________________________________________________________________

__________________________________________________________________________________________________
