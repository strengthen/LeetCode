__________________________________________________________________________________________________
sample 100 ms submission
import heapq
import itertools


class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        m = len(nums1)
        n = len(nums2)
        
        next_pos1 = self.get_next_pos(nums1)
        next_pos2 = self.get_next_pos(nums2)
        
        solution = [None] * k
        
        candidates = [(0, 0)]
        for l in range(k):
            candidates = self.prune_candidates(candidates)
            num = self.select_num(candidates, next_pos1, next_pos2, m, n, k - l)
            solution[l] = num
            if l == k - 1:
                break
            next_candidates = []
            for i, j in candidates:
                if next_pos1[i][num] is not None and m - next_pos1[i][num] + n - j >= k - l:
                    next_candidates.append((next_pos1[i][num] + 1, j))
                if next_pos2[j][num] is not None and m - i + n - next_pos2[j][num] >= k - l:
                    next_candidates.append((i, next_pos2[j][num] + 1))
            candidates = next_candidates
            
        return solution

    def get_next_pos(self, nums):
        m = len(nums)
        next_pos = [None] * (m + 1)
        next_pos[m] = [None] * 10
        for i in reversed(range(m)):
            next_pos[i] = next_pos[i + 1].copy()
            next_pos[i][nums[i]] = i
        return next_pos
    
    def select_num(self, candidates, next_pos1, next_pos2, m, n, remaining):
        for num in reversed(range(10)):
            for i, j in candidates:
                if next_pos1[i][num] is not None and m - next_pos1[i][num] + n - j >= remaining:
                    break
                if next_pos2[j][num] is not None and m - i + n - next_pos2[j][num] >= remaining:
                    break
            else:
                continue
            return num
        
    def prune_candidates(self, candidates):
        i_min_j = {}
        j_min_i = {}
        pruned_candidates = []
        for i, j in candidates:
            if i in i_min_j and i_min_j[i] <= j:
                continue
            if j in j_min_i and j_min_i[j] <= i:
                continue
            pruned_candidates.append((i, j))
            i_min_j[i] = j
            j_min_i[j] = i
        return pruned_candidates
__________________________________________________________________________________________________
sample 13152 kb submission
class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        # to get k numbers in array A to max the number
        def getMax(A, k):
            res = []
            n = len(A) 
            for i in range(n):
                while res and len(res) + n - i > k and A[i] > res[-1]:
                    res.pop()
                res.append(A[i])
            return res[:k]
        
        def merge(A, B):
            m, n = len(A), len(B)
            res, i, j, p = [0] * (m + n), 0, 0, 0
            while i < m or j < n:
                if i == m:
                    res[p] = B[j]
                    j += 1
                elif j == n:
                    res[p] = A[i]
                    i += 1
                elif greater(A, B, i, j):
                    res[p] = A[i]
                    i += 1
                else:
                    res[p] = B[j]
                    j += 1
                p += 1
            return res
        
        def greater(A, B, i, j):
            m, n = len(A), len(B)
            while i < m and j < n and A[i] == B[j]:
                i, j = i + 1, j + 1
            return j == n or i < m and j < n and A[i] > B[j]
        
        res = [0] * k
        m, n = len(nums1), len(nums2)
        for i in range(max(0, k - n), min(m, k) + 1):
            tep = merge(getMax(nums1, i), getMax(nums2, k - i))
            if greater(tep, res, 0, 0): res = tep
        return res
        # return merge(getMax(nums1, 3), getMax(nums2, 2))
__________________________________________________________________________________________________
