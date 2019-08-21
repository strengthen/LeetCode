__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    # def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        
    def flipAndInvertImage(self, A):
        return [[1 ^ i for i in row[::-1]] for row in A]
__________________________________________________________________________________________________
sample 12924 kb submission
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for row in (A):
            for i in range((len(row)+1)//2):
                row[i], row[~i] = row[~i]^1, row[i]^1
        return A        
__________________________________________________________________________________________________
