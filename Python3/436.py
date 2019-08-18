__________________________________________________________________________________________________
sample 292 ms submission
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        out = []
        if not intervals:
            return out
        indexmap = {}
        starts = [i[0] for i in intervals]
        for i, start in enumerate(starts):
            indexmap[start] = i
        starts.sort()
        for start,end in intervals:
            if end in indexmap:
                out.append(indexmap[end])
            else:
                i = 0
                j = len(starts) - 1
                result = None
                while i <= j:
                    mid = (i + j) // 2
                    if starts[mid] > end:
                        result = starts[mid]
                        j = mid - 1
                    else:
                        i = mid + 1
                out.append(-1 if result is None else indexmap[result])
        return out
__________________________________________________________________________________________________
sample 16616 kb submission
class Solution:
    def findRightInterval(self, intervals):
        l = sorted((e[0], i) for i, e in enumerate(intervals))
        res = []
        for e in intervals:
            r = bisect.bisect_left(l, (e[1],))
            res.append(l[r][1] if r < len(l) else -1)
        return res
__________________________________________________________________________________________________
