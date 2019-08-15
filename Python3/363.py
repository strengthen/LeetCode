__________________________________________________________________________________________________
sample 528 ms submission
class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        m,n=len(matrix),len(matrix[0])
        res=float('-inf')
        for col1 in range(n):
            sums=[0]*m
            for col2 in range(col1,n):
                for row in range(m):
                    sums[row]+=matrix[row][col2]
                cur=maxv=float('-inf')
                for s in sums:
                    cur=max(s,cur+s)
                    maxv=max(maxv,cur)
                if maxv<=k:
                    res=max(res,maxv)
                else:
                    for i in range(m):
                        tempsum=0
                        for j in range(i,m):
                            tempsum+=sums[j]
                            if tempsum<=k:
                                res=max(res,tempsum)
                                if res==k:
                                    return k
        return res
__________________________________________________________________________________________________
sample 13640 kb submission
class Solution:
    def maxSubArraylessK(self,nums,k):
        """
        we need to find the sum[right]-sum[left]<=k
        since the bitsect return the index of the sorted value
        we can't directly pop the nums[idx] 
        we should use insort from the bisect
        """
        # python set() doesn't support indexing, using list instead
        # similar as the c++ or java set()
        
        cumset=[]
        cumset.append(0)
        maxsum=-1<<32
        cursum=0
        for i in range(len(nums)):
            cursum+=nums[i]
            # find the lower bound of the index
            idx=bisect.bisect_left(cumset,cursum-k)
            # find max in sum[right]-sum[left]<=k
            if 0<=idx<len(cumset):
                maxsum=max(maxsum,cursum-cumset[idx])
            # using insort instead of append since bisect_left reason
            bisect.insort(cumset,cursum)
        return maxsum
    
    
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        """
        The python solution hasn't a good time performance,
        since lack some of the datatype to do 
        I am trying to imitate the way solved in c++ or Java
        Ther related quesiton might be:
        1. #53. Maximum Subarray 
        2. Maximum Subarray sum less or equal than K
        3. maximun sum of rectangle 
        """
        if not matrix or not matrix[0]:
            return 0
        row,col=len(matrix),len(matrix[0])
        res=-(1<<32)
        # using two pointer to record the scan position
        for left in range(col):
            # reset mem to store the row data
            cursums=[0 for _ in range(row)]
            # since the rectange has area>0 
            right=left
            while right<col:
                # count one row
                for i in range(row):
                    cursums[i]+=matrix[i][right]
                # find the max in this row
                curarrmax=self.maxSubArraylessK(cursums,k)
                res=max(res,curarrmax)
                right+=1
                
        return res
__________________________________________________________________________________________________
