__________________________________________________________________________________________________
sample 804 ms submission
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        
        n,cnt=len(nums),0
        arr=[-1]
        for i in range(n):
            if nums[i]%2:
                arr.append(i)
        m=len(arr)
        if m<k+1: return 0
        arr.append(n)
        i,j=1,k       
        while j<m:
            cnt+=(arr[i]-arr[i-1])*(arr[j+1]-arr[j])
            i+=1
            j+=1
        return cnt
__________________________________________________________________________________________________
sample 816 ms submission
import collections

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        mydict = collections.deque()
        for i in range(k):
            mydict.appendleft(0)
        zero = 0
        final_res = 0
        for val in nums:
            # print(mydict)
            zero += 1
            if val % 2 == 1:
                final = mydict.pop()
                final_res += final * zero
                mydict.appendleft(zero)
                zero = 0
        final = mydict.pop()
        final_res += (zero + 1) * final
        return final_res
__________________________________________________________________________________________________
