__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        N = len(arr)
        l = target // N
        r = target
        minDiff = target * N
        ans = l
        for i in range(l, r):
            ind = bisect.bisect(arr, i)
            diff = abs(target - (sum(arr[:ind]) + (N-ind) * i))
            if diff < minDiff:
                minDiff = diff
                ans = i
            else:
                break
        return ans
__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        current_sum = 0
        for i in range(len(arr)):
            diff = target - current_sum
            rate = round(diff / (len(arr) - i))
            
            if arr[i] >= rate:
                return rate
            
            current_sum += arr[i]
        
        return round(target / len(arr))
__________________________________________________________________________________________________
