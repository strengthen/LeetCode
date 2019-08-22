__________________________________________________________________________________________________
sample 236 ms submission
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        counts=collections.Counter([t%60 for t in time])
        result=0
        if 0 in counts:
            result+=counts[0]*(counts[0]-1)/2
            del counts[0]
        if 30 in counts:
            result+=counts[30]*(counts[30]-1)/2
            del counts[30]
        for key in counts:
            if 60-key in counts:
                result+=counts[key]*counts[60-key]/2
        return int(result)
__________________________________________________________________________________________________
sample 15272 kb submission
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        time_mod = dict()
        for i in time:
            time_mod[i%60] = 1 if i%60 not in time_mod else time_mod[i%60]+1
        
        cnt = 0
        for i in time_mod.keys():
            print([i, time_mod[i]])
            if i==30 or i==0:
                cnt += time_mod[i]*(time_mod[i]-1)//2
            else:
                cnt += time_mod[i]*(time_mod[60-i] if 60-i in time_mod else 0)/2
        
        return int(cnt)
__________________________________________________________________________________________________
