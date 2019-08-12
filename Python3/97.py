__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if not s1 and not s2 and not s3:
            return True
        if not s1:
            return True if s2 == s3 else False
        if not s2:
            return True if s1 == s3 else False
        
        length1 = len(s1)
        length2 = len(s2)
        length3 = len(s3)
        if length1 + length2 != length3:
            return False
        
        memo = [[-1] * length2 for row in range(length1)]
        
    
        def helper(idx1, idx2, idx3):
            #print("idx1, idx2 are ",idx1, idx2)
            if idx1 == length1 and idx2 == length2:
                #print("True and return previous level")
                return True 
            
            if idx1 < length1 and idx2 < length2 and memo[idx1][idx2] >= 0:
                return memo[idx1][idx2]

            if idx1 == length1:
                if s3[idx3] == s2[idx2]:
                    ans = helper(idx1, idx2+1, idx3+1)
                    memo[idx1-1][idx2] = ans
                    #print("condition: end s1 and s2 == s3", memo)
                    return ans
                else:
                    #print("condition: end s1 and no match!", memo)
                    return False
            
            if idx2 == length2:
                if s3[idx3] == s1[idx1]:
                    ans = helper(idx1+1, idx2, idx3+1)
                    memo[idx1][idx2-1] = ans
                    #print("condition: end s2 and s1 == s3", memo)
                    return ans
                else:
                    #print("condition: end s2 and no match!", memo)
                    return False
            
            if s3[idx3] == s1[idx1] and s3[idx3] == s2[idx2]:
                ans = helper(idx1+1, idx2, idx3+1) or helper(idx1, idx2+1, idx3+1)
                memo[idx1][idx2] = ans
                #print("condition: s1 == s3 and s2 == s3", memo)
                return ans
            elif s3[idx3] == s1[idx1]:
                ans = helper(idx1+1, idx2, idx3+1)
                memo[idx1][idx2] = ans
                #print("condition: s1 == s3", memo)
                return ans
            elif s3[idx3] == s2[idx2]:
                ans = helper(idx1, idx2+1, idx3+1)
                memo[idx1][idx2] = ans
                #print("condition: s2 == s3", memo)
                return ans
            else:
                #print("condition: no match!", memo)
                return False
        
        return helper(0,0,0)
__________________________________________________________________________________________________
sample 13184 kb submission

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)
        if l1 == 0: return s2==s3
        if l2 == 0: return s1==s3
        if l1+l2 != l3: return False

        dp = [[None]*(l2+1) for _ in range(l1+1)]
        dp[0][0] = True

        return self.isInterleave_dp(s1,s2,s3,dp)

    def isInterleave_dp(self,s1,s2,s3,dp):
        l1 = len(s1)
        l2 = len(s2)
        assert(dp[l1][l2] == None)
        dp[l1][l2] = False

        if l1 > 0:
            # (l1-1, l2) branch
            if dp[l1-1][l2] == None:
                dp[l1-1][l2] = self.isInterleave_dp(s1[:-1],s2,s3[:-1],dp)
            if dp[l1-1][l2] == True and s1[-1] == s3[-1]: 
                dp[l1][l2] = True

        if l2 > 0:
            # (l1, l2-1) branch
            if dp[l1][l2-1] == None:
                dp[l1][l2-1] = self.isInterleave_dp(s1,s2[:-1],s3[:-1],dp) 
            if dp[l1][l2-1] == True and s2[-1] == s3[-1]:
                dp[l1][l2] = True

        # print("%d %d %d" % (l1,l2,dp[l1][l2]))
        return dp[l1][l2]
__________________________________________________________________________________________________
