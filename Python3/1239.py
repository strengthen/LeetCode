__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        
        arr = [item for item in arr if len(item) == len(set(item))]
        
        def check(a, b):
            c = a + b
            return len(set(c)) == len(c)
        
        search = {}
        n = len(arr)
        for i in range(n-1):
            for j in range(i+1, n):
                search[(arr[i], arr[j])] = check(arr[i], arr[j])
        
        def maxSubLength(arr, search, dp):
            n = len(arr)
            if dp.get(tuple(arr)) is not None:
                return dp.get(tuple(arr))
            
            if n == 0:
                return 0
            
            if n == 1:
                return len(arr[0])
            
            narr = []
            for j in range(1, n):
                if search[(arr[0], arr[j])]:
                    narr.append(arr[j])
            
            contains = len(arr[0]) + maxSubLength(narr, search, dp)
            notContains = maxSubLength(arr[1:], search, dp)
            maxValue = max(contains, notContains)
            
            dp[tuple(arr)] = maxValue
            
            return maxValue
        
        dp = {}
        return maxSubLength(arr, search, dp)
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        arr = [s for s in arr if len(s) == len(set(s))]
        if not arr:
            return 0
        
        arr.sort(reverse=True, key=len)
        max_len = 0
        
        for i in range(len(arr)):
            tmp = arr[i]
            for j in range(len(arr)):
                if not set(tmp) & set(arr[j]):
                    tmp += arr[j]
            max_len = max(max_len, len(tmp))
        
        return max_len
__________________________________________________________________________________________________
