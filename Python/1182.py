__________________________________________________________________________________________________
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        dic = collections.defaultdict(list)
        for i, c in enumerate(colors):
            dic[c].append(i)
            
        def bs(arr, target):
            l, r = 0, len(arr) - 1
            while l <= r:
                mid = (l + r) // 2
                if arr[mid] == target:
                    return mid
                if arr[mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1
            return l
        
        res = []
        for q in queries:
            if q[1] not in dic:
                res.append(-1)
            else:
                index = bs(dic[q[1]], q[0])
                if index < len(dic[q[1]]) and dic[q[1]][index] == q[0]:
                    res.append(0)
                else:
                    if 0 < index < len(dic[q[1]]):
                        res.append(min(abs(dic[q[1]][index] - q[0]), abs(dic[q[1]][index - 1] - q[0])))
                    elif index == len(dic[q[1]]):
                        res.append(abs(dic[q[1]][index - 1] - q[0]))
                    else:
                        res.append(abs(dic[q[1]][index] - q[0]))
        return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
