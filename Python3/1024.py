__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        clips.sort()
        count = 0
        stitched_end = 0
        candidate_end = 0

        for start, end in clips+[[float('inf'), float('inf')]]:
            if start > stitched_end: # no overlap
                stitched_end = candidate_end
                count += 1
                if stitched_end >= T:
                    break

            if start <= stitched_end:   # overlap, with stitched_end
                                        # adjusted or unadujsted
                candidate_end = max(candidate_end, end)

        return count if stitched_end>=T else -1
__________________________________________________________________________________________________
sample 13248 kb submission
class Solution:
    def videoStitching(self, clips, T: int) -> int:        
        cnt=0
        total=0
        select=True
        while total<T and select:# and len(clips)<
            select=False
            aa=[]
            for k in clips:
                if k[0]<=total and k[1]>total:
                    aa.append(k[1])                    
                    select=True
            cnt+=1
            if select:
                total=max(total,max(aa))
        return -1 if T>total else cnt
__________________________________________________________________________________________________
