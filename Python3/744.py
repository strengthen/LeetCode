__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if target >= letters[-1]:
            return letters[0]
        
        left = 0
        right = len(letters) - 1
        while left + 1 < right:
            mid = (left + right) // 2
            if letters[mid] <= target:
                left = mid
            else:
                right = mid
        if letters[left] > target:
            return letters[left]
        else:
            return letters[right]
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        
        from bisect import bisect_right as b_index
        
        ln_l = len(letters)
        
        i = b_index(letters, target)
        if i == ln_l:   return letters[0]
        else:           return letters[i]
__________________________________________________________________________________________________
