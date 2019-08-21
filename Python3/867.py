__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        return map(list,zip(*A))
__________________________________________________________________________________________________
sample 13548 kb submission
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        #2D list
        #[col][row]
        #[i][j]
        
        #switch the size 2 X 3 for A then a 3 X 2 for B
        rows = len(A[0])
        cols = len(A)

        #This is what's called a "list comprehension"
        B = [ ([0] * cols) for row in range(rows) ]

            
        #loop through 
        #for every row i and every column j get value in A
        #for every column j and every row i put value in B
        i = 0
        j = 0
        
        for i in range(len(A)): #rows
            for j in range(len(A[0])): # cols
                B[j][i] = A[i][j]

        return B
__________________________________________________________________________________________________
