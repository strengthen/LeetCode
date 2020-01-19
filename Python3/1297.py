__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        return next((i for x, i in collections.Counter(s[i-minSize:i] for i in range(minSize, len(s)+1)).most_common() if len(set(x)) <= maxLetters), 0)
__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        counts = collections.Counter([s[i:i+minSize] for i in range(len(s)-minSize + 1)])
        
        return max([counts[sub] for sub in counts.keys() if len(set(sub)) <= maxLetters] + [0])
__________________________________________________________________________________________________
