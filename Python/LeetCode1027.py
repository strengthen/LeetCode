__________________________________________________________________________________________________
456ms
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        idxs = collections.defaultdict(list)

        for i, v in enumerate(nums):
            idxs[v].append(i)

        ans = 0
        cnts = collections.Counter()

        for k in range(len(nums)):         # last
            for j in range(k):             # middle
                v = 2 * nums[j] - nums[k]  # first

                if v in idxs:
                    for i in idxs[v]:
                        if i >= j: break
                        cnts[j, k] = max(cnts[j, k], cnts[i, j] + 1)
                        ans = max(ans, cnts[j, k])

        return ans + 2
__________________________________________________________________________________________________
464ms
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        N = len(A)
        cache = [[2]*N for _ in range(N)]
        loc = {}
        loc[A[0]] = [0]
        
        maxlength = 2
        for j in range(1, N):
            for i in range(j-1, -1, -1):
                diff = A[j] - A[i]
                if A[i]-diff in loc:
                    for pidx in loc[A[i]-diff]:
                        if pidx < i:
                            cache[i][j] = max(cache[i][j], cache[pidx][i] + 1)
                    if cache[i][j] > maxlength:
                        maxlength = cache[i][j]
            if A[j] not in loc:
                loc[A[j]] = [j]
            else:
                loc[A[j]] += [j]
        return maxlength

__________________________________________________________________________________________________
472ms
from collections import defaultdict
class Solution:
    def longestArithSeqLength(self, A):
        N = len(A)
        cache = [[2]*N for _ in range(N)]
        loc = defaultdict(list)
        loc[A[0]] = [0]
        
        maxlength = 2
        for j in range(1, N):
            for i in range(j-1, -1, -1):
                diff = A[j] - A[i]
                if A[i]-diff in loc:
                    for pidx in loc[A[i]-diff]:
                        if pidx < i:
                            cache[i][j] = max(cache[i][j], cache[pidx][i] + 1)
                    if cache[i][j] > maxlength:
                        maxlength = cache[i][j]
            if A[j] not in loc:
                loc[A[j]] = [j]
            else:
                loc[A[j]] += [j]
        return maxlength
__________________________________________________________________________________________________
476ms
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        N = len(A)
        cache = [[2]*N for _ in range(N)]
        loc = collections.defaultdict(list)
        loc[A[0]] = [0]
        
        maxlength = 2
        for j in range(1, N):
            for i in range(j-1, -1, -1):
                diff = A[j] - A[i]
                if A[i]-diff in loc:
                    for pidx in loc[A[i]-diff]:
                        if pidx < i:
                            cache[i][j] = max(cache[i][j], cache[pidx][i] + 1)
                    if cache[i][j] > maxlength:
                        maxlength = cache[i][j]
            if A[j] not in loc:
                loc[A[j]] = [j]
            else:
                loc[A[j]] += [j]
        return maxlength
__________________________________________________________________________________________________
484ms
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        N = len(A)
        cache = [[2]*N for _ in range(N)]
        loc = collections.defaultdict(list)
        loc[A[0]] += [0]
        
        maxlength = 2
        for j in range(1, N):
            for i in range(j-1, -1, -1):
                diff = A[j]-A[i]
                if A[i]-diff in loc:
                    for previ in loc[A[i]-diff]:
                        if previ >= i:                  # this is the key line ... make sure previ < i, before we update cache[i][j]
                            break
                        cache[i][j] = max(cache[i][j], cache[previ][i] + 1)
                    maxlength = max(cache[i][j], maxlength)
            loc[A[j]] += [j]
        return maxlength
__________________________________________________________________________________________________