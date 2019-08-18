__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        
        res =  []
        
        
        for x in range(1,n+1):
            if  not x%3 and not x%5:
                res.append('FizzBuzz')
            elif not x%3:
                res.append('Fizz')
            elif not x%5:
                res.append('Buzz')
            else:
                res.append(str(x))
                
        return res
__________________________________________________________________________________________________
sample 13908 kb submission
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        for i in range(1, n + 1):
            if i % 15 == 0:
                ans.append("FizzBuzz")
            elif i % 5 == 0:
                ans.append("Buzz")
            elif i % 3 == 0:
                ans.append("Fizz")
            else:
                ans.append(str(i))
        return ans
__________________________________________________________________________________________________
