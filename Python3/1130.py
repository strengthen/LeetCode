__________________________________________________________________________________________________
sample 136 ms submission
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[[0, float("-inf")] for i in range(n + 1)] for j in range(n)]
        for i in range(n):
            dp[i][i + 1][1] = arr[i]
        for w in range(2, n + 1):
            for i in range(n + 1 - w):
                dp[i][i + w] = [min(dp[i][j][1] * dp[j][i + w][1] + dp[i][j][0] + dp[j][i + w][0] for j in range(i + 1, i + w)), max(dp[i][i + 1][1], dp[i + 1][i + w][1])]
        return dp[0][n][0]
__________________________________________________________________________________________________
sample 240 ms submission
from functools import lru_cache

class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:

        # return: max_leaf_value, sum_of_non_leaf_node
        @lru_cache(maxsize=None)
        def contruct_tree(arr):
            if len(arr) == 1:
                #print(arr, 0)
                return arr[0], 0
            if len(arr) == 2:
                #print(arr, arr[0] * arr[1])
                return max(arr), arr[0] * arr[1]

            min_sum = float('inf')
            for i in range(1, len(arr)):
                left = contruct_tree(arr[:i])
                right = contruct_tree(arr[i:])
                sum_of_non_leaf_node = left[0] * right[0] + left[1] + right[1]
                if sum_of_non_leaf_node < min_sum:
                    min_sum = sum_of_non_leaf_node
            #print(arr, min_sum)
            return max(arr), min_sum

        arr = tuple(arr)
        max_leaf_value, sum_of_non_leaf_node = contruct_tree(arr)
        return sum_of_non_leaf_node
__________________________________________________________________________________________________
