__________________________________________________________________________________________________
sample 672 ms submission
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:               
        M, N = len(mat), len(mat[0])
        res = 0
        colsum = [0 for i in range(N)]
        for i in range(M):
            for j in range(N):
                colsum[j] += mat[i][j]
            l = res + 1
            s = sum(colsum[:l])
            prev_res = res
            if s <= threshold:
                res = l
            else:
                for k in range(0, N - l):
                    s -= colsum[k]
                    s += colsum[k + l]
                    if s <= threshold:
                        res = l
                        break
            if res >= min(M, N):
                break
            if prev_res == res:
                for j in range(N):
                    colsum[j] -= mat[i - prev_res][j]
        return res
__________________________________________________________________________________________________
sample 688 ms submission
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        M, N = len(mat), len(mat[0])
        res = 0
        colsum = [0 for i in range(N)]
        for i in range(M):
            for j in range(N):
                colsum[j] += mat[i][j]
            # print(colsum)
            # print(res)
            l = res + 1
            s = sum(colsum[:l])
            prev_res = res
            if s <= threshold:
                res = l
                # print(f'{s}, {t}')
            else:
                for k in range(0, N - l):
                    s -= colsum[k]
                    s += colsum[k + l]
                    if s <= threshold:
                        res = l
                        break
            if res >= min(M, N):
                break
            if prev_res == res:
                for j in range(N):
                    colsum[j] -= mat[i - prev_res][j]
        return res
__________________________________________________________________________________________________
