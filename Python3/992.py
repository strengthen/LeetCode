__________________________________________________________________________________________________
sample 396 ms submission
import copy
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:        
        if not A:
            return 0
        if K > len(set(A)):
            return 0
        
        dic = {A[0]: 0}
        i = 0
        j = 0
        res = 0
        
        while len(dic) < K:
            j += 1
            dic[A[j]] = j
        
        mk, mv = min(dic.items(), key = lambda x: x[1])
        
        while j < len(A):
            dic[A[j]] = j
            l = len(dic)
            # print(j, dic, mk, mv, A[mv])
            # print(dic[A[mv]] )
            
            if A[j] == mk:
                while dic[mk] != mv:
                    mv += 1
                    mk = A[mv]
                
            elif l > K:
                del dic[mk]
                mv += 1
                i = mv
                mk = A[mv]
                while dic[mk] != mv:
                    mv += 1
                    mk = A[mv]
                    
            res += mv - i + 1
                
            j += 1
            # print(i, j, l, dic, mi, mv, res)
                
        return res
            
__________________________________________________________________________________________________

__________________________________________________________________________________________________
