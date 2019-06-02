__________________________________________________________________________________________________
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        for row in matrix:
            for i in range(1,len(row)):
                row[i] += row[i-1]
        res = 0
        for i in range(len(matrix)):
            tmp = [0 for val in matrix[i]]
            for j in range(i,len(matrix)):
                need = collections.defaultdict(int)
                need[target] = 1
                for k in range(len(matrix[0])):
                    tmp[k] += matrix[j][k]
                    if tmp[k] in need:
                        res += need[tmp[k]]
                    need[tmp[k]+target] += 1
        return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
