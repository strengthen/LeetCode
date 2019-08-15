__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        rows = len(matrix)-1
        col = 0
        start = matrix[rows][col]
        while True:
            if rows < 0 or col >= len(matrix[0]):
                return False
            if matrix[rows][col] == target:
                return True
            elif matrix[rows][col] > target and rows >= 0:
                rows -= 1
            elif matrix[rows][col] < target and col < len(matrix[0]):
                col += 1
        return
__________________________________________________________________________________________________
sample 17216 kb submission
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def bisect(array, start, end, tgt):
            while start < end:
                mid = (start + end) // 2
                if tgt == array[mid]:
                    return True
                elif tgt > array[mid]:
                    start = mid + 1
                else:
                    end = mid
            return False
        for m in matrix:
            ret = bisect(m, 0, len(m), target)
            if ret:
                return True
        return False
__________________________________________________________________________________________________
