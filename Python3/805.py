__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        L, total = len(A), sum(A)
        A.sort()
        
        '''个数不会超过数组总个数的一半 + 1'''
        for i in range(1, L // 2 + 1):
            '''
                i个数 x sum（A） ==  i个数之和 x len(A)
                所以 sum（A） x i ➗ len(A) == i个数之和 必然是整数
            '''
            if total * i % L:
                continue
                
                
            ''' 从数组A中，找到k个数之和等于target的可能性'''
            k, target, index = i, total * i // L, 0
            
            if self.dfs(A, k, target, index):
                return True
        
        return False
            
    
    ''' 
		从数组A中，找到k个数之和等于target的可能性
		combination sum II 或者 k sum那两道题的简易版
	'''
    def dfs(self, A, k, target, index):
        if not k and not target:
            return True
        
        if not k or target < 0:
            return False

        for i in range(index, len(A)):
            if i > index and A[i] == A[i -1]:
                continue
            
            if target < A[i] * k or target > A[-1] * k:
                break
                
            if self.dfs(A, k - 1, target - A[i], i + 1):
                return True
        
        return False
__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        A.sort()
        
        L, total = len(A), sum(A)
        
        for k in range(1, L // 2 + 1):
            if total * k % L: 
                continue
            
            start_index, target = 0, total * k // L
            if self.dfs(A, k, start_index, target):
                return True
        
        return False
    
    
    def dfs(self, A, k, start_index, target):
        if k == 0 and target == 0:
            return True
        
        if k == 0 or target <= 0:
            return False
        
        if start_index < len(A) and target < k * A[start_index] or target > k * A[-1]:
            return False
        
        for i in range(start_index, len(A)):
            if i > start_index and A[i] == A[i - 1]:
                continue
            
            if self.dfs(A, k - 1, i + 1, target - A[i]):
                return True        
__________________________________________________________________________________________________
