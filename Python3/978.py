__________________________________________________________________________________________________
sample 492 ms submission
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        
        # maybe find indices that are the min/maxes of a zigzag
        
        if len(A) == 1:
            return 1
        maxturblength = 1
        turblength = 0
        maxTurb = False
        minTurb = False
        for i in range(1,len(A)-1):
            if maxTurb:
                # last thing was a max turb, so see if A[i] is a min turb
                
                if A[i] < A[i+1]:
                    minTurb = True
                    maxTurb = False
                    turblength += 1
                else:
                    maxTurb = False
                    minTurb = False
                    if turblength > maxturblength:
                        maxturblength = turblength
                    turblength = 0
            
            elif minTurb:
                
                if A[i] > A[i+1]:
                    maxTurb = True
                    minTurb = False
                    turblength += 1
                else:
                    maxTurb = False
                    minTurb = False
                    if turblength > maxturblength:
                        maxturblength = turblength
                    turblength = 0
            else:
                
                if A[i] > A[i-1] and A[i] > A[i+1]:
                    maxTurb = True
                    minTurb = False
                    turblength = 3
                elif A[i] < A[i-1] and A[i] < A[i+1]:
                    minTurb = True
                    maxTurb = False
                    turblength = 3
            
            #print(i,A[i],maxTurb,minTurb,turblength)
        if turblength > maxturblength:
            return turblength
        if maxturblength == 1:
            # if we didn't find any zigzags at all, this will be 1
            # but if the sequence isn't constant, it should be 2!
            for i in range(0,len(A)-1):
                if A[i] != A[i+1]:
                    return 2
            return 1
        return maxturblength
__________________________________________________________________________________________________
sample 15120 kb submission
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        n = len(A)
        for i in range(n-1):
            if A[i+1]==A[i]:
                A[i] = 0
            elif A[i+1]>A[i]:
                A[i] = 1 if i&1 else -1
            else:
                A[i] = -1 if i&1 else 1
        res = 0
        cur = 0
        last = 0
        for i in range(n-1):
            if A[i] == 0:
                res = max(res,cur)
                cur = 0
                last = 0
            elif A[i]>0:
                if last >0:
                    cur +=1
                elif last ==0:
                    cur = 1
                    last = 1
                elif last<0:
                    res = max(res,cur)
                    cur = 1
                    last = 1
            elif A[i]<0:
                if last < 0:
                    cur +=1
                elif last ==0:
                    cur = 1
                    last = -1
                elif last>0:
                    res = max(res,cur)
                    cur = 1
                    last = -1
        res = max(res,cur)
        return res+1
__________________________________________________________________________________________________
