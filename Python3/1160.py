__________________________________________________________________________________________________
Runtime: 520 ms
Memory Usage: 14.2 MB
from collections import Counter

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        return len(''.join(filter(lambda x : len(Counter(x) - Counter(chars)) == 0, words)))
__________________________________________________________________________________________________

__________________________________________________________________________________________________
