__________________________________________________________________________________________________
sample 220 ms submission
class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        calories = [0] + calories
        cur = sum(calories[:k])
        point = 0
        for i in range(k, len(calories)):
            cur -= calories[i - k]
            cur += calories[i]
            if cur > upper:
                point += 1
            if cur < lower:
                point -= 1
        return point
__________________________________________________________________________________________________
sample 224 ms submission
class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        res = 0
        cum = sum(calories[:k])
        if cum > upper:
            point = 1
        elif cum < lower:
            point = -1
        else:
            point = 0
        res += point
        for i in range(k, len(calories)):
            cum += calories[i] - calories[i-k]
            if cum > upper:
                point = 1
            elif cum < lower:
                point = -1
            else:
                point = 0
            res += point
        return res
__________________________________________________________________________________________________
