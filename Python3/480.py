__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        window = sorted(nums[:k])
        res = []
        if k % 2 == 0:
            res.append((window[k // 2] + window[k // 2 - 1]) / 2)
        else:
            res.append(window[k // 2])
        
        for i in range(k, len(nums)):
            bisect.insort(window, nums[i])
            index = bisect.bisect_left(window, nums[i - k])
            window.pop(index)
            if k % 2 == 0:
                res.append((window[k // 2] + window[k // 2 - 1]) / 2)
            else:
                res.append(window[k // 2])
        return res
__________________________________________________________________________________________________
sample 14492 kb submission
def sortedInsert(arr, ele):
    pos = len(arr)
    for i, n in enumerate(arr):
        if ele < n:
            pos = i 
            break
    arr.insert(pos, ele)
    
def populate(nums, k):
    low = 0
    high = k - 1
    window = sorted(nums[:k])
    return low, high, window


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        low, high, window = populate(nums, k)
        result = []
        while high < len(nums) - 1:
            if k % 2 == 1:
                result.append(float(window[int(k/2)]))
            else:
                a = window[int(k/2)]
                b = window[int(k/2) - 1]                
                result.append(float((a+b)/2))            
            window.remove(nums[low])
            low += 1
            high += 1
            sortedInsert(window, nums[high])
        if k % 2 == 1:
            result.append(float(window[int(k/2)]))
        else:
            a = window[int(k/2)]
            b = window[int(k/2) - 1]                
            result.append(float((a+b)/2))            
        return result
__________________________________________________________________________________________________
