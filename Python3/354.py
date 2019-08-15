__________________________________________________________________________________________________
sample 160 ms submission
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes = sorted(envelopes, key = lambda x: (x[0], -x[1]))
        dp = []
        for env in envelopes:
            h = env[1]
            ins_pos = bisect.bisect_left(dp, h)
            if ins_pos == len(dp):
                dp.append(h)
            else:
                dp[ins_pos] = h
        return len(dp)
__________________________________________________________________________________________________
sample 14764 kb submission
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        def bs(num):
            left, right = 0, len(rank)-1
            while left <= right:
                mid = (left + right) // 2
                if num > rank[mid] : left = mid+1
                else: right = mid-1
                    
            return left
        if not envelopes: return 0
        envelopes.sort(key=lambda x:x[1], reverse=True)
        envelopes.sort(key=lambda x:x[0])
        res = 0
        rank = [envelopes[0][1]]
        for i in range(1, len(envelopes)):
            index = bs(envelopes[i][1])
            if index == len(rank):
                rank.append(envelopes[i][1])
            else:
                rank[index] = envelopes[i][1]
        return len(rank)
__________________________________________________________________________________________________
