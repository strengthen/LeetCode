__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def minFlips(self, a, b, c):
        xor = b ^ c
        g = xor & ~a
        t = a & ~c
        h = t & b

        sum1 = g | h
        str_1 = str(bin(t))[2:]
        str_2 = str(bin(sum1))[2:]

        final_1 = map(lambda x: int(x), str_1)
        final_2 = map(lambda x: int(x), str_2)
        return sum(final_1) + sum(final_2)
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        m=[2**(30-i) for i in range(31)]
        ans=0
        for i in range(31):
            xa=a//m[i]
            a%=m[i]
            xb=b//m[i]
            b%=m[i]
            xc=c//m[i]
            c%=m[i]
            print(xa,xb,xc)
            if xc==1 and xa+xb==0:
                ans+=1
            elif xc==0:
                ans+=xa+xb
        return ans
__________________________________________________________________________________________________
