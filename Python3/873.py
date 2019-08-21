__________________________________________________________________________________________________
sample 128 ms submission
class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        A_set = set(A)
        result = 2
        for i in range(len(A) - 1):
            for j in range(i + 1, len(A)):
                a, b = A[i], A[j]
                length = 2
                if b * (result - 2) >= A[-1]:
                    break
                while a + b in A_set:
                    a, b = b, a + b
                    length += 1
                result = max(result, length)
        return result if result > 2 else 0
__________________________________________________________________________________________________
sample 13376 kb submission
class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        index = {x: i for i, x in enumerate(A)}
        longest = collections.defaultdict(lambda: 2)
        ans = 0
        for k in range(len(A)):
            for j in range(k):
                i = index.get(A[k]-A[j])
                if i is not None and i < j:
                    cand = longest[j, k] = longest[i, j] + 1
                    ans = max(ans, cand)
        
        return ans if ans >= 3 else 0
__________________________________________________________________________________________________
