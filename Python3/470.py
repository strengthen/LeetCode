__________________________________________________________________________________________________
sample 420 ms submission
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        call rand7() twice, this gives us 49 numbers with the same probability
        num1*7**0 + num2*7**1 is [8, 56]
        if number is [11, 50] return number % 10 if not 0 else 10
        if number is not in [11, 50] draw two number again
        """
        
        while True:
            
            a = rand7()
            b = rand7()
            num = b + 7*(a-1)
            
            if num <= 40:
                return 1 + (num-1) % 10
            
            a = num - 40
            b = rand7()
            num = b + 7*(a-1)
            
            if num <= 60:
                return 1 + (num-1) % 10
            
            a = num - 60
            b = rand7()
            num = b + 7*(a-1)
            if num <= 20:
                return 1 + (num-1) % 10
__________________________________________________________________________________________________
sample 424 ms submission
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            ans = (rand7() - 1) * 7 + rand7()
            if ans <= 40:
                return (ans % 10) + 1
__________________________________________________________________________________________________
