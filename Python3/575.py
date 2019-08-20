__________________________________________________________________________________________________
sample 900 ms submission
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        totalCount = int(len(candies) / 2)
        typesCount = len(set(candies))
        return min(totalCount, typesCount)
__________________________________________________________________________________________________
sample 14520 kb submission
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        d = {}
        for i in candies:
            d[i] = 1
        if len(d) > len(candies) // 2:
            return len(candies) // 2
        return len(d)
__________________________________________________________________________________________________
