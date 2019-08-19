__________________________________________________________________________________________________
sample 356 ms submission
class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        lookup = collections.defaultdict(list)
        for i, a in enumerate(A): # reverse table
            lookup[a] += [i]
        dp = [{} for _ in range(len(A))]
        #  只计算前一个 剩下的从前一个的记录中取
        for k, num in enumerate(A):# 对于每个数字
            for i in range(0, k): # 遍历之前的数字
                diff = A[k] - A[i] # 记录它们之间的差距
                X = A[i] - diff # 需要寻找的前一个数字
                if X in lookup:# 如果存在这个数字
                    for index in lookup[X]: # 找到所有可以遍历该位置的数量并且将动态规划的数字加1
                        # print(index)
                        if index < i:
                            dp[k][diff] = dp[k].get(diff, 0) + 1
                        else: break
                if diff in dp[i]: # 继承前面的人的数量
                    dp[k][diff] = dp[k].get(diff, 0) + dp[i][diff]
        return sum([x[k] for x in dp for k in x])
__________________________________________________________________________________________________
sample 50096 kb submission
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        dp = [collections.defaultdict(int) for _ in range(n)]
        res=0
        for i in range(1, n):
            for j in range(i):
                diff = A[i]-A[j]
                dp[i][diff] += 1
                if diff in dp[j]:
                    dp[i][diff] += dp[j][diff] 
                    res += dp[j][diff]
        return res
__________________________________________________________________________________________________
