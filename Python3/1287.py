__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        for idx, num in enumerate(arr):
            if arr[idx] == arr[idx+len(arr)//4]: return num
__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        size = int((len(arr)) / 4)
        loose = max(1, size)
        for index in range(0, len(arr), loose):
            candidate = arr[index]
            left = bisect.bisect_left(arr, candidate, max(0, index - loose), min(len(arr), index + loose))
            right = bisect.bisect_right(arr, candidate, max(0, index - loose), min(len(arr), index + loose))
            if right - left > size:
                return arr[index]
        assert(False)
__________________________________________________________________________________________________
