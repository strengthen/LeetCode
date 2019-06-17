__________________________________________________________________________________________________
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        from collections import defaultdict
        import bisect
        lookup = defaultdict(list)
        for idx, score in items:
            bisect.insort_left(lookup[idx], score)
        # print(lookup)
        res = []
        for i in range(len(lookup)):
            avg = (sum(lookup[i + 1][-5:])) // 5
            res.append([i + 1, avg])
        return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
