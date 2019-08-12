__________________________________________________________________________________________________
sample 24 ms submission
# Iteration | Time: O(n^2) | Space: O(n)
class Solution:
    # @param n: int
    # @reutrn List[List[int]]
    def generateMatrix(self, n):
        if n == 0:
            return []

        # initialize
        nums = [x for x in range(1, n**2 + 1)]
        matrix = [[None for _ in range(n)] for _ in range(n)]
        rowStart, rowEnd = 0, n - 1
        colStart, colEnd = 0, n - 1
        index = 0

        while index < len(nums) and rowStart <= rowEnd and colStart <= colEnd:

            # upper row
            for j in range(colStart, colEnd + 1):
                matrix[rowStart][j] = nums[index]
                index += 1
            rowStart += 1

            # right column
            for i in range(rowStart, rowEnd + 1):
                matrix[i][colEnd] = nums[index]
                index += 1
            colEnd -= 1

            # bottom row
            if rowStart <= rowEnd:
                for j in range(colEnd, colStart - 1, -1):
                    matrix[rowEnd][j] = nums[index]
                    index += 1
                rowEnd -= 1
            
            # left column
            if colStart <= colEnd:
                for i in range(rowEnd, rowStart - 1, -1):
                    matrix[i][colStart] = nums[index]
                    index += 1
                colStart += 1

        return matrix
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return [[]]
        if n == 1:
            return [[1]]
        
        index = 1
        left_bound, right_bound = 0, n - 1
        top_bound, bottom_bound = 0, n - 1
        
        pointer = left_bound
        matrix = [[0] * n for _ in range(n)]

        while index <= n ** 2:
            # left -> right
            while index <= n ** 2 and pointer <= right_bound:
                matrix[top_bound][pointer] = index
                index += 1
                pointer += 1

            pointer = top_bound + 1
            top_bound += 1

            # top -> bottom
            while index <= n ** 2 and pointer <= bottom_bound:
                matrix[pointer][right_bound] = index
                index += 1
                pointer += 1

            pointer = right_bound - 1
            right_bound -= 1

            # right -> left
            while index <= n ** 2 and pointer >= left_bound:
                matrix[bottom_bound][pointer] = index
                index += 1
                pointer -= 1

            pointer = bottom_bound - 1
            bottom_bound -= 1

            # bottom -> top
            while index <= n ** 2 and pointer >= top_bound:
                matrix[pointer][left_bound] = index
                index += 1
                pointer -= 1

            pointer = left_bound + 1
            left_bound += 1
            
        return matrix
__________________________________________________________________________________________________
