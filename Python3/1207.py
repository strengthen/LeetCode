__________________________________________________________________________________________________
sample 324 ms submission
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurrences = list(collections.Counter(arr).values())
        for i, a in enumerate(occurrences):
            for b in occurrences[:i]:
                if a == b:
                    return False
        return True
__________________________________________________________________________________________________
sample 332 ms submission
from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        return len(set(arr)) == len(set(Counter(arr).values()))
__________________________________________________________________________________________________
