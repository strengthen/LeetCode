__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        counter = collections.Counter(text)
        return min(counter["a"], counter["b"], counter["n"], min(counter["l"], counter["o"]) // 2)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
