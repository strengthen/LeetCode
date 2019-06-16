__________________________________________________________________________________________________
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        count = collections.defaultdict(int)   
        combine = sorted(zip(values, labels), reverse=True)
        result = length = 0
        for v,l in combine:
            if count[l] < use_limit:
                count[l] += 1
                result += v
                length += 1
                if length == num_wanted:break
        return result
__________________________________________________________________________________________________

__________________________________________________________________________________________________
