__________________________________________________________________________________________________
sample 20 ms submission

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return solve(heights)

def solve(a):
    b = a[:]
    b.sort()
    return sum((1 for i in range(len(a)) if a[i] != b[i]))

def sp(*a):
    assert solve(*a[:-1]) == a[-1]
    pass

def test():
    sp([1], 0)
    sp([1, 2], 0)
    sp([2, 1], 2)
    sp([1, 1, 4, 2, 1, 3], 3)
    pass
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        sorted_heights = sorted(heights)
        cnt = 0
        for i in range(len(heights)):
            if sorted_heights[i] != heights[i]:
                cnt += 1
        return cnt
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def heightChecker(self, height: List[int]) -> int:
        return sum(1 if a!=0 else 0 for a in [a-b for a,b in zip(sorted(height), height)] )