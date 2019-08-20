__________________________________________________________________________________________________
sample 320 ms submission
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # binary search
        left = 0
        right = len(arr) - k
        while left < right:
            mid = left + (right - left) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid
        return arr[left : left + k]
__________________________________________________________________________________________________
sample 14048 kb submission
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        lb = 0
        ub = len(arr) - 1
        arrUb = ub
        found = False
        
        while lb <= ub:
            mid = int((lb + ub) / 2)
            if arr[mid] == x:
                found = True
                break
            if arr[mid] < x:
                lb = mid + 1
            else:
                ub = mid - 1
        
        uperList = []
        lowerList = []
        itemsAdded = 0
        lowerArrIndex = ub
        uperArrIndex = lb
        
        if (found):
            uperList.append(arr[mid])
            lowerArrIndex = mid - 1
            uperArrIndex = mid + 1
            itemsAdded += 1
        
        while itemsAdded < k:
            if lowerArrIndex < 0:
                uperList.append(arr[uperArrIndex])
                uperArrIndex += 1
            elif uperArrIndex > arrUb:
                lowerList.append(arr[lowerArrIndex])
                lowerArrIndex -= 1
            elif x - arr[lowerArrIndex] <= arr[uperArrIndex] - x:
                lowerList.append(arr[lowerArrIndex])
                lowerArrIndex -= 1
            elif x - arr[lowerArrIndex] > arr[uperArrIndex] - x:
                uperList.append(arr[uperArrIndex])
                uperArrIndex += 1
            itemsAdded += 1
        
        lowerList.reverse()
        return lowerList + uperList
__________________________________________________________________________________________________
