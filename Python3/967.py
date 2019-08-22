__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        
        res = []
        startD = 0 if N == 1 else 1

        for i in range(startD, 10):
          prev = [i]
          for _ in range(N-1):
            curr = []
            for p in prev:
              lastD = p % 10
              if lastD - K >= 0:
                curr.append(p * 10 + lastD - K)
              if lastD + K <= 9 and K != 0:
                curr.append(p * 10 + lastD + K)  
                
            prev = curr
          
          res = res + prev
          
        return res
__________________________________________________________________________________________________
sample 13168 kb submission
class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        if N == 1:
            return [i for i in range(10)]
        
        if K == 0:
            return [int(str(i)*N) for i in range(1, 10)]
        
        que = [str(i) for i in range(1, 10)]
        while que and len(que[0]) < N:
            q = que.pop(0)
            if int(q[-1]) + K <= 9:
                que.append(q + str(int(q[-1]) + K))
            
            if int(q[-1]) - K >= 0:
                que.append(q + str(int(q[-1]) - K))
        
        return [int(i) for i in que]
__________________________________________________________________________________________________
