__________________________________________________________________________________________________
sample 264 ms submission
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries:
            return 0
        
        total_duration = 0
        current_end = timeSeries[0]
        for attack in timeSeries:
            attack_end = attack + duration
            if attack > current_end:
                total_duration += duration
            else:
                total_duration += attack_end - current_end
            current_end = attack_end
                
        return total_duration
__________________________________________________________________________________________________
sample 268 ms submission
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        res = 0
        if not timeSeries: return 0
        prev = timeSeries[0]
        for value in timeSeries[1:]:
            if value > prev+duration:
                res += duration
            else:
                res += value-prev
            prev = value
        return res+duration
__________________________________________________________________________________________________
