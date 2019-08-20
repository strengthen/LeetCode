__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def checkRecord(self, n: int) -> int:
        """
        The idea is that we first check the strings without 
        'A' and then we find out the state to be
        f[n] = 2*f[n-1] - f[n-4]
        
        and how the state transitions over time
        
        """
        """
        M = 10**9 + 7
        a010, a011, a012, a110, a111, a112 = 1, 0, 0, 0, 0, 0
        for i in range(n):
            a010_ = (a010+a011+a012) % M
            a012 = a011
            a011 = a010
            a010 = a010_
            a110_ = (a010 + a110+ a111 + a112) % M
            a112 = a111
            a111 = a110
            a110 = a110_
        
        return (a010+a011+a012+a110+a111+a112) % M
        """
        mod = 1000000007        
        def mul(a, b):
            n, m, l = len(a), len(b[0]), len(a[0])
            return [[sum([a[i][k] * b[k][j] for k in range(l)]) % mod for j in range(m)] for i in range(n)]
        
        B = [[1, 1, 1, 0, 0 ,0],
             [1, 0, 0, 0, 0 ,0],
             [0, 1, 0, 0, 0 ,0],
             [1, 1, 1, 1, 1 ,1],
             [0, 0, 0, 1, 0 ,0],
             [0, 0, 0, 0, 1 ,0]]
        
        f = [[1], [0], [0], [0], [0], [0]]
        
        Bn = B
        while n > 0:
            if n & 1:
                f = mul(Bn, f)
            n = n >> 1
            Bn = mul(Bn, Bn)
                
        return mul([[1, 1, 1, 1, 1, 1]], f)[0][0]
__________________________________________________________________________________________________
sample 84 ms submission
"""
dp[a][l][i]: 前i个中出现a个A, 最后连续的L的个数为l的所有可能的记录的数量
"""
class Solution:
    def myMatrixMulti(self, a, b):
        c = [[0] * 6 for i in range(6)]
        for i in range(6):
            for j in range(6):
                for k in range(6):
                    c[i][j] += a[i][k] * b[k][j] % 1000000007
                c[i][j] = c[i][j] % 1000000007
        return c
    
    def myMatrixPower(self, x, n):
        ans = [
            [1,0,0,0,0,0],[0,1,0,0,0,0],[0,0,1,0,0,0],
            [0,0,0,1,0,0],[0,0,0,0,1,0],[0,0,0,0,0,1]
        ]
        while n > 0:
            if (n & 1):
                ans = self.myMatrixMulti(ans, x)
            x = self.myMatrixMulti(x, x)
            n >>= 1
        return ans
            
    def checkRecord(self, n: int) -> int:
        if n == 0:
            return 0 
        M = [
            [1,1,1,0,0,0],[1,0,0,0,0,0],[0,1,0,0,0,0],
            [1,1,1,1,1,1],[0,0,0,1,0,0],[0,0,0,0,1,0]
        ]
        MM = self.myMatrixPower(M, n)
        ans = sum([MM[i][0] for i in range(6)]) % 1000000007
        return ans
__________________________________________________________________________________________________
