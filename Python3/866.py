__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def primePalindrome(self, N: int) -> int:
        def isPrime(n): # only input odd number
            return all(n%i for i in range(3, int(n**0.5)+1, 2))
        
        if N <= 11:
            return {1:2, 2:2, 3:3, 4:5, 5:5, 6:7, 7:7, 8:11, 9:11, 10:11, 11:11}[N]
        
        # all even length palindrome number must could be divided by 11, so it is not prime number unless it is 11 itself
        # all prime palindrome number > 11 will be odd length, so it have a middle digit
        if len(str(N))%2 == 0:
            leftN = int('1'+'0'* (len(str(N))//2))
        else:
            leftN = int(str(N)[:len(str(N))//2+1])
        while leftN < 20000: # max answer will be less than 2*10**9
            leftS = str(leftN)
            if int(leftS[0])%2 == 0: # jump all number which first digit is even
                leftS = str(int(leftS[0])+1) + '0'*(len(leftS)-1)
            cand = int(leftS + leftS[:-1][::-1])
            if cand >= N and isPrime(cand):
                return cand
            leftN += 1
__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def primePalindrome(self, N: int) -> int:
        def isPrime(n): # only input odd number
            return all(n%i for i in range(3, int(n**0.5)+1, 2))
        
        if N <= 11:
            if N <= 2:
                return 2
            if N%2 == 0:
                N += 1
            while N <= 11:
                if isPrime(N):
                    return N
                N += 2
        
        S = str(N)
        if S[::-1] == S and isPrime(N): # it is palindrome already
            return N
        # all even length palindrome number must could be divided by 11, so it is not prime number unless it is 11 itself
        if len(S)%2 == 0:
            S = '1' + '0' * len(S)
        # all prime palindrome number > 11 will be odd length, so it have a middle digit
        leftS = S[:len(S)//2+1]
        leftN = int(leftS)
        while leftN < 20000: # max answer will be less than 2*10**9
            leftS = str(leftN)
            if int(leftS[0])%2 == 0:
                leftS = str(int(leftS[0])+1) + '0'*(len(leftS)-1)
            cand = int(leftS + leftS[:-1][::-1])
            if cand >= N and isPrime(cand):
                return cand
            leftN += 1
__________________________________________________________________________________________________
