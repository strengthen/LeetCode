__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        i = 0
        h = 0
        cnt = collections.defaultdict(int)
        aboveH = 0
        
        for x in citations:
            if x <= h:
                continue
                
            aboveH += 1
            cnt[x] += 1
            
            # print(aboveH, h, cnt[h])
            
            if aboveH - h >= 1:
                h += 1
                aboveH -= cnt[h]
                
        return h
__________________________________________________________________________________________________
sample 13212 kb submission
class Solution:

    def hIndex(self, citations: List[int]) -> int:

        citations.sort()

        for i in range(len(citations) ):



            if citations[i]>=len(citations)-i: 

                return len(citations)-i 

        return 0
__________________________________________________________________________________________________
