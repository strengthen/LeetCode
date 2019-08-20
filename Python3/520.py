__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        c = 0
        for i in word:
            if i.isupper():
                c += 1
        return len(word) == c or c == 0 or (c == 1 and word[0].isupper())
__________________________________________________________________________________________________
sample 13036 kb submission
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        count = 0
        for char in word:
            if char.isupper():
                count += 1
                
        n = len(word)
        
        return count == 0 or count == n or (count == 1 and word[0].isupper())
__________________________________________________________________________________________________
