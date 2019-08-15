__________________________________________________________________________________________________
sample 104 ms submission
import collections
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if nums == []:
            return []
        counter = collections.Counter(nums)
        nums = sorted(counter.keys())
        n = len(nums)
        max_num, max_val = nums[0], counter[nums[0]]
        
        res = dict()
        res[nums[0]] = -1, counter[nums[0]]
        for i in range(1, n):
            x = nums[i]
            sqrt_ = min(int(math.sqrt(x) + 0.5) + 1, x + 1)
            pre, best = -1, 0
            for j in range(1, sqrt_):
                if x % j == 0:
                    tmp = res.get(j, (-1, -1))[1]
                    if tmp > best:
                        pre = j
                        best = tmp
                    u = x // j
                    tmp = res.get(u, (-1, -1))[1]
                    if tmp > best:
                        pre = u
                        best = tmp
            res[x] = pre, best + counter[x]
            if res[x][1] > max_val:
                max_val = res[x][1]
                max_num = x
        
        ans = []
        while max_num != -1:
            for _ in range(counter[max_num]):
                ans.append(max_num)
            max_num = res[max_num][0]
        return list(reversed(ans))        
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0:
            return []
        
        dp = [[1, i] for i in range(n)]
        nums.sort()
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if 1 + dp[j][0] > dp[i][0]:
                        dp[i][0] = 1 + dp[j][0]
                        dp[i][1] = j
        
        mi = 0
        mx = 0
        for i in range(n):
            if dp[i][0] > mx:
                mx = dp[i][0]
                mi = i
        
        ans = []
        i = mi
        while dp[i][1] < i:
            ans.append(nums[i])
            i = dp[i][1]
        
        return [nums[i]] + ans
__________________________________________________________________________________________________
