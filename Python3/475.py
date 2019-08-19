__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()
        heaters1=set(heaters)
        rslt=0
        for h in houses:
            if h not in heaters1:   
                pos=bisect.bisect(heaters,h)
                if pos==0:
                    rslt=max(rslt,heaters[0]-h)
                elif pos==len(heaters):
                    rslt=max(rslt,h-heaters[-1])
                else:                
                    rslt=max(rslt,min(h-heaters[pos-1],heaters[pos]-h))
        return rslt 
__________________________________________________________________________________________________
sample 15640 kb submission
import bisect
class Solution:
    def findRadius(self, houses: 'List[int]', heaters: 'List[int]') -> 'int':
        houses.sort()
        heaters.sort()
        ans = 0
        for i in houses:
            temp = bisect.bisect_left(heaters, i)
            if temp == 0 :
                ans = max(ans,abs(heaters[temp] - i))
            elif temp == len(heaters):
                ans = max(ans,abs(heaters[temp - 1] - i))
            else:
                ans = max(ans,min(abs(heaters[temp] - i), abs(heaters[temp - 1] - i)))
        return ans
__________________________________________________________________________________________________
