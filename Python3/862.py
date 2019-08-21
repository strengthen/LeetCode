__________________________________________________________________________________________________
sample 856 ms submission
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        NOT_FOUND = -1
        
        if not nums:
            return NOT_FOUND
        
        n = len(nums)
        ans = n + 1
        total = 0
        queue = collections.deque([(-1, 0)])
        
        for i, x in enumerate(nums):
            total += x
            
            if x > 0:
                while queue and total - queue[0][1] >= k:
                    ans = min(ans, i - queue.popleft()[0])
            else:
                while queue and total <= queue[-1][1]:
                    queue.pop()
            
            queue.append((i, total))
        
        return ans if ans <= n else NOT_FOUND
__________________________________________________________________________________________________
sample 17160 kb submission
class Solution:
    
     def shortestSubarray(self, A: List[int], K: int) -> int:
        if len(A) ==0:
            return -1
       
        begin=0
        end=0
        # start with a non-negative number
        while A[begin]<=0 and begin<len(A):
            begin +=1
            end+=1
        
        c_sum=0
        size = len(A)
        found=False
        
        while end <len(A):
            c_sum += A[end]
            modified= False if c_sum <K else True
            if c_sum >= K:
                found=True
                
            # we know the first element won't be negative
            # if the element is negative try and spread it's value to previous elements
            if A[end]<0:
                if begin == end:
                    begin+=1
                    c_sum=0
                else:
                    i=1
                    to_save = abs(A[end])
                    while to_save > 0:
                        while A[end-i] ==0 and end-i>=begin:
                            i+=1
                        if end-i <begin:
                            begin = end+1
                            c_sum=0
                            to_save=0
                            break
                        else:
                            if to_save > A[end-i]:
                                to_save -=A[end-i]
                                A[end-i]=0
                            else:
                                A[end-i] -= to_save
                                A[end]=0
                                to_save=0
                

            else:
                # while the element you are adding compensates 
                # for moving the begin by one to the right and makes/keeps sum >= K
                while A[end] >= A[begin] + K-(c_sum-A[end]):
                    c_sum-=A[begin]
                    if c_sum <K:
                        c_sum+=A[begin]
                        break
                    else:
                        begin+=1
                        size = min(size,end-begin+1)
                if c_sum >=K:
                    size = min(size,end-begin+1)
                    
            end +=1
            
        if found:
            return size
        else:
            return -1
__________________________________________________________________________________________________
