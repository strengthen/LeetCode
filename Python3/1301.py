__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        MOD = 10 ** 9 + 7
        maxSum1 = [0] * n
        count1 = [0] * n
        count1[-1] = 1
        for j in range(n - 2, -1, -1):
            if board[-1][j] == 'X':
                break
            else:
                maxSum1[j] = maxSum1[j + 1] + int(board[-1][j])
                count1[j] = 1
        # print(maxSum1, count1)    
        for i in range(n - 2, -1, -1):
            maxSum2 = [0] * n
            count2 = [0] * n
            if count1[-1] > 0 and board[i][-1] != 'X':
                maxSum2[-1] = maxSum1[-1] + int(board[i][-1])
                count2[-1] = 1
            for j in range(n - 2, -1, -1):
                if board[i][j] != 'X' and not (count2[j + 1] == count1[j] == count1[j + 1] == 0):                    
                    max1 = maxSum2[j + 1]
                    max2 = maxSum1[j]
                    max3 = maxSum1[j + 1]
                    maxSum2[j] = int(board[i][j]) if board[i][j] != 'E' else 0
                    if max1 > max2:
                        if max1 > max3:
                            maxSum2[j] += max1
                            count2[j] = count2[j + 1]
                        elif max1 == max3:
                            maxSum2[j] += max1
                            count2[j] = (count2[j + 1] + count1[j + 1]) % MOD
                        else:
                            maxSum2[j] += max3
                            count2[j] = count1[j + 1]
                    elif max1 == max2:
                        if max3 > max1:
                            maxSum2[j] += max3
                            count2[j] = count1[j + 1]
                        elif max3 == max1:
                            maxSum2[j] += max1
                            count2[j] = (count2[j + 1] + count1[j] + count1[j + 1]) % MOD
                        else:
                            maxSum2[j] += max1
                            count2[j] = (count2[j + 1] + count1[j]) % MOD
                    else:
                        if max2 > max3:
                            maxSum2[j] += max2
                            count2[j] = count1[j]
                        elif max2 == max3:
                            maxSum2[j] += max2
                            count2[j] = (count1[j] + count1[j + 1]) % MOD
                        else:
                            maxSum2[j] += max3
                            count2[j] = count1[j + 1]
            maxSum1 = maxSum2
            count1 = count2
            # print(maxSum1, count1)
            
        return [maxSum1[0], count1[0]]
__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        row, col = len(board), len(board[0])
        board = list(map(list, board))
        board[0][0] = "0"
        board[-1][-1] = "0"
        dp = [[[0, 0] for _ in range(col + 1)] for _ in range(row + 1)]
        dp[0][0][1] = 1
        MOD = 10 ** 9 + 7
        
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'X':
                    continue
                
                s, p = dp[i][j + 1]
                s2, p2 = dp[i + 1][j]
                if s2 == s:
                    p += p2
                elif s2 > s:
                    s, p = s2, p2
                s3, p3 = dp[i][j]
                if s3 == s:
                    p += p3
                elif s3 > s:
                    s, p = s3, p3
                dp[i + 1][j + 1] = [s + int(board[i][j]), p % MOD]
        if dp[-1][-1][1] == 0:
            return [0, 0]
        return dp[-1][-1]
__________________________________________________________________________________________________
