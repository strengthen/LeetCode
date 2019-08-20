__________________________________________________________________________________________________
sample 224 ms submission
#非常巧妙地一种办法，依次遍历，以s2作为base，dp[i]表示在第i个元素作为结尾能获得的最大ASCII值，利用前一轮的值作为base，当然要比较prev和last取较大值作为base。既保证了顺序，又保证了max
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        if not s2 or not s2: return 
        n1, n2 =len(s1), len(s2)
        dp = [0]*n2#以此做记录，按照s2的顺序，每个元素作为结尾时能取到的最大值
        
        for i in range(n1):
            prev = 0#每重新遍历一个s1时初始值设为0
            for j in range(n2):
                last=dp[j]#把dp[j]记录与前一个比大小，取大值赋值给下一个prev
                if s1[i] == s2[j]:
                    dp[j] = prev +ord(s1[i])
                if prev <= last:
                    prev = last
        
        return sum([ord(s) for s in (s1+s2)]) - 2*max(dp)
__________________________________________________________________________________________________
sample 17644 kb submission
class Solution:
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        R, C = len(s1) + 1, len(s2) + 1
        dp = [[0] * C for _ in range(R)]
        for r in range(1, R):
            dp[r][0] = dp[r - 1][0] + ord(s1[r - 1])
        for c in range(1, C):
            dp[0][c] = dp[0][c - 1] + ord(s2[c - 1])
        for r in range(1, R):
            for c in range(1, C):
                if s1[r - 1] == s2[c - 1]:
                    dp[r][c] = dp[r - 1][c - 1]
                else:
                    dp[r][c] = min(dp[r - 1][c] + ord(s1[r - 1]), dp[r][c - 1] + ord(s2[c - 1]))
        return dp[-1][-1]
__________________________________________________________________________________________________
