__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    '''
    # LTE
    def threeSumMulti(self, A: List[int], target: int) -> int:
        A.sort()
        count = 0
        for i in range(len(A)):
            j, k = i+1, len(A)-1
            while j < k:
                s = A[i] + A[j] + A[k]
                if s < target:
                    j += 1
                elif s > target:
                    k -= 1
                else:
                    if A[j] == A[k]:
                        count += (k-j+1) * (k-j) // 2
                        break
                    else:
                        jc, kc = 1, 1
                        j += 1
                        while A[j] == A[j-1]:
                            j += 1
                            jc += 1
                        k -= 1
                        while A[k] == A[k+1]:
                            k -= 1
                            kc += 1
                        count += jc * kc
        return count % (10 **9 + 7)
    '''
    def threeSumMulti(self, A: List[int], target: int) -> int:
        from collections import Counter
        cc = Counter(A)
        c = list(cc.items())
        c.sort()
        count = 0
        for i in range(len(c)):
            for j in range(i, len(c)):
                ii, ic = c[i]
                jj, jc = c[j]
                kk = target - ii - jj
                if kk in cc and kk >= jj:
                    if ii == jj == kk:
                        if ic >= 3:
                            count += ic * (ic-1) * (ic-2) // 6
                    elif ii == jj:
                        if ic >= 2:
                            count += ic * (ic-1) // 2 * cc[kk]
                    elif jj == kk:
                        if jc >= 2:
                            count += jc * (jc-1) // 2 * ic
                    else:
                        count += ic * jc * cc[kk]
        return count % (10 **9 + 7)
__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        
        
        counter = collections.Counter(A)
        keys = sorted(counter)
        
        res = 0
        mod = 10**9+7
        
        
        for i,val in enumerate(keys):
            
            find = target - val
            
            l = i
            r = len(keys)-1
            
            
            while l <= r:
                
                left = keys[l]
                right = keys[r]
                
                if left + right > find:
                    r-=1
                    
                elif left + right < find:
                    l+=1
                    
                else:
                    
                    if i < l < r:
                        
                        res += counter[val] * counter[left] * counter[right]
                        
                    elif i == l < r:
                        
                        res += counter[left] * (counter[left]-1)/2 * counter[right]
                        
                    elif i < l == r:
                        
                        res += counter[val] * (counter[left]-1)/2 * counter[left]
                        
                    else:
                        res += counter[right] * (counter[right]-1) * (counter[right] -2) /6
                        
                    l+=1
                    r-=1
                    
                    
        return int(res)%mod   
__________________________________________________________________________________________________
