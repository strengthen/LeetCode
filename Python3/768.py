__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        
        for n in arr:
            if not stack or stack[-1] <= n:
                stack.append(n)
            else:
                tmp = stack[-1]
                while stack and stack[-1] > n:
                    stack.pop()
                stack.append(tmp)
        
        return len(stack)
__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        sorted_arr = sorted(arr)
        D = {}
        for i in range(len(sorted_arr)):
            if sorted_arr[i] not in D:
                D[sorted_arr[i]] = i
        earliest_finish_index = 0
        count = 0
        res = 0
        for i in range(len(arr)):
            if D[arr[i]] > earliest_finish_index:
                earliest_finish_index = D[arr[i]]
                count = 1
            elif D[arr[i]] == earliest_finish_index:
                count += 1
            if earliest_finish_index <= i and i + 1 - count >= earliest_finish_index:
                res += 1
        return res
__________________________________________________________________________________________________
