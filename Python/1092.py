__________________________________________________________________________________________________
class Solution(object):
    def shortestCommonSupersequence(self, s1, s2):
        # find longest sub in s2 that is also sub in s1.
        #dp[i][j]=max:dp[i-1][j],dp[i][j-1], or dp[i-1][j-1]+s1[i-1] if s1[i]==s2[j]
        m,n=len(s1),len(s2)
        dp=[[""]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                
                if s1[i-1]==s2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+s1[i-1]
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1],key=lambda x:len(x))
        s=dp[m][n]
       
        #two pointer to insert
        i,j=0,0
        res=[]
        for ch in s:
            newi=s1.find(ch,i)
            newj=s2.find(ch,j)
            
            res.append(s1[i:newi])
            res.append(s2[j:newj])
            res.append(ch)
            i,j=newi+1,newj+1
     
        res.append(s1[i:])
        res.append(s2[j:])
        return "".join(res)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
