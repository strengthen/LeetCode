__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        r = set(ransomNote)
        for i in r:
            if ransomNote.count(i) > magazine.count(i):
                return False
        return True
__________________________________________________________________________________________________
sample 13260 kb submission
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for char in ransomNote:
            if char in magazine:
                magazine = magazine.replace(char, '', 1)
            else:
                return False
        return True
__________________________________________________________________________________________________
