__________________________________________________________________________________________________
sample 172 ms submission
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        height = [0 for i in range(len(matrix[0]))]
        k = 0
        for i in range(len(matrix)):
            max_length = 0
            length = 0
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
                if height[j] > k:
                    length += 1
                    max_length = max(max_length, length)
                else:
                    length = 0
            if max_length > k:
                k += 1
        return k**2
__________________________________________________________________________________________________
sample 13728 kb submission
class Solution(object):

    def get_tl(self, matrix, y, x):
        result = []
        for r, c in [(y-1, x), (y, x-1), (y-1, x-1)]:
            if r >= 0 and c >= 0:
                curr = matrix[r][c]
                result.append(curr)
            else:
                result.append(0)
        return result

    def maximalSquare(self, matrix):
        result = 0
        for y, row in enumerate(matrix):
            for x, num in enumerate(row):
                matrix[y][x] = int(num)
        for y, row in enumerate(matrix):
            for x, num in enumerate(row):
                if not num:
                    continue
                curr = num
                top, left, top_left = self.get_tl(matrix, y, x)
                curr = min(top, left, top_left) + 1
                matrix[y][x] = curr
                result = max(result, curr)
        return result**2
__________________________________________________________________________________________________
