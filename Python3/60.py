__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numbers = list(range(1, n + 1))
        permutation = ''
        k -= 1
        while n > 0:
            n -= 1
            i, k = k // math.factorial(n), k % math.factorial(n)
            permutation += str(numbers[i])
            numbers.remove(numbers[i])
        return permutation        
__________________________________________________________________________________________________
sample 13108 kb submission
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = ''
        nums = list(range(1, n+1))
        k = k - 1
        for i in range(n, 0, -1):
            x = k//self.factorial(i-1)
            k = k%self.factorial(i-1)
            ans += str(nums.pop(x))
        return ans
            
    def factorial(self, n):
        product = 1
        for i in range(1, n+1):
            product = product*i
        return product
__________________________________________________________________________________________________
