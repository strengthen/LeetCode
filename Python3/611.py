__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def triangleNumber(self, A):
        B = max(A)
        if B == 0: return 0
        count = [0] * (B+1)
        N = 0
        for x in A:
            if x:
                count[x] += 1
                N += 1
        keys = [x for x in range(B+1) if count[x]]

        psum = [0]
        for c in count:
            psum.append(psum[-1] + c)

        #count[x] = the number of sticks of length x
        #psum[x] = the number of sticks < length x

        ans = 0
        for i1, k1 in enumerate(keys):
            for i2 in range(i1, len(keys)):
                k2 = keys[i2]
                #ans += multiplicity * (number of sticks < k1 + k2) 
                if i1 != i2:
                    multiplicity = count[k1] * count[k2]
                else:
                    multiplicity = count[k1] * (count[k1] - 1) / 2

                if k1 + k2 <= B:
                    ans += multiplicity * psum[k1 + k2]
                else:
                    multiplicity += count[k1] * (psum[-1] - psum[k2+1])
                    ans += multiplicity * N
                    break

        return int(ans - N*(N*N - 1)/3)
__________________________________________________________________________________________________
sample 12956 kb submission
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        lst = sorted(nums)
        
        N = len(lst)
        
        cnt = 0
        for i in range(N-2):
            for j in range(i+1, N-1):
                master = lst[i] + lst[j]
                
                hi = len(lst)
                lo = j + 1
                
                while lo < hi:
                    mid = (lo + hi) // 2
                    
                    if master > lst[mid]:
                        lo = 1 + mid
                    else:
                        hi = mid
                        
                idx = lo - 1
                
                cnt += (idx - j)
                
        return cnt
__________________________________________________________________________________________________
