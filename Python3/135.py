__________________________________________________________________________________________________
sample 160 ms submission
class Solution:
    def candy(self, ratings: List[int]) -> int:
        ans = 0
        up, down = 0, 1
        pre = 0

        for cur in ratings:
            if cur >= pre:
                if down > 1:
                    if down > up:
                        ans += down - up
                    up = down = 1
                up = 1 if cur == pre else up + 1
                ans += up
            else:
                ans += down
                down += 1

            pre = cur

        if down > up:
            ans += down - up

        return ans
__________________________________________________________________________________________________
sample 15008 kb submission
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)

        res = [1 for _ in ratings]

        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                res[i] = res[i - 1] + 1

        for i in reversed(range(0, n - 1)):
            if ratings[i] > ratings[i + 1] and res[i] <= res[i + 1]:
                res[i] = res[i + 1] + 1

        count = 0
        for i in res:
            count += i

        return count
__________________________________________________________________________________________________
