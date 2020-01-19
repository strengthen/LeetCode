__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        count = collections.defaultdict(list)
        for i, size in enumerate(groupSizes):
            count[size].append(i)
        return [l[i:i+s] for s, l in count.items() for i in range(0,len(l),s)]
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        result = {}
        for index, val in enumerate(groupSizes):
            try:
                result[val].append(index)
            except:
                result[val] = [index]

        final_result = []
        for n in sorted(result):
            if n == len(result[n]):
                final_result.append(result[n])
            else:
                final_result.extend([result[n][i:i + n] for i in range(0, len(result[n]), n)])
                
        return final_result
__________________________________________________________________________________________________
