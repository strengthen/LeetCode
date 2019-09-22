__________________________________________________________________________________________________
sample 404 ms submission
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = float("inf")
        ans = []
        for i in range(len(arr) - 1):
            diff = arr[i + 1] - arr[i]
            if diff > min_diff:
                continue
            elif diff == min_diff:
                ans.append([arr[i], arr[i + 1]])
            else:
                ans = [[arr[i], arr[i + 1]]]
                min_diff = diff
        return ans
__________________________________________________________________________________________________
sample 408 ms submission
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        MIN = min(b - a for a, b in zip(arr[:-1], arr[1:]))
        return [[a, b] for a, b in zip(arr[:-1], arr[1:]) if b - a == MIN]
__________________________________________________________________________________________________
