__________________________________________________________________________________________________
sample 208 ms submission
class Solution:
    def minDistance(self, s: str, t: str) -> int:
        """Modified Wagner-Fischer algorithm"""
        if len(s) < len(t):
            s, t = t, s

        pre = [None] * (len(t) + 1)
        cur = list(range(len(pre)))

        for i, sc in enumerate(s, 1):
            pre, cur = cur, pre
            cur[0] = i

            for j, tc in enumerate(t, 1):
                if sc == tc:
                    cur[j] = pre[j - 1]
                else:
                    cur[j] = 1 + min(cur[j - 1], pre[j])

        return cur[-1]
__________________________________________________________________________________________________
sample 13276 kb submission
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        memory = [0 for j in range(m+1)]
        for i in range(1, n+1):
            temp = [0 for j in range(m+1)]
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    temp[j] = memory[j - 1] + 1
                else:
                    temp[j] = max(memory[j], temp[j-1])
            memory = temp
        return n+m - 2*memory[m]
__________________________________________________________________________________________________
