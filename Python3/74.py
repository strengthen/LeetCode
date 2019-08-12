__________________________________________________________________________________________________
sample 64 ms submission
#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#
# https://leetcode.com/problems/search-a-2d-matrix/description/
#
# algorithms
# Medium (34.42%)
# Total Accepted:    186.8K
# Total Submissions: 542.8K
# Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
#
# Write an efficient algorithm that searches for a value in an m x n matrix.
# This matrix has the following properties:
# 
# 
# Integers in each row are sorted from left to right.
# The first integer of each row is greater than the last integer of the
# previous row.
# 
# 
# Example 1:
# 
# 
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 3
# Output: true
# 
# 
# Example 2:
# 
# 
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 13
# Output: false
# 
#
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        r, c = len(matrix), len(matrix[0])
        f, l = 0, r * c
        while f < l:
            m = f + (l - f) // 2
            if matrix[m // c][m % c] < target:
                f = m + 1
            else:
                l = m
        return f < r * c and matrix[f // c][f % c] == target        
__________________________________________________________________________________________________
sample 13712 kb submission
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def isListEmpty(inList):
            if isinstance(inList, list): # Is a list
                return all( map(isListEmpty, inList) )
            return False
        if isListEmpty(matrix):
            return False
        numrows = len(matrix)
        numcols = len(matrix[0])
        col = 0
        row = 0
        while row < numrows:
            if target == matrix[row][col]:
                return True
            elif target > matrix[row][col] and row != (numrows -1):
                row += 1
            elif target > matrix[row][col] and row == (numrows -1):
                break
            elif target < matrix[row][col] and row != 0:
                row -= 1
                break
            else:
                break
        while col < numcols:
            if target == matrix[row][col]:
                return True
            elif target > matrix[row][col] and col != (numcols -1):
                col += 1
            elif target > matrix[row][col] and col == (numcols -1):
                return False
            elif target < matrix[row][col] and col != 0:          
                return False
            else:
                return False
__________________________________________________________________________________________________
