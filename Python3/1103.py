__________________________________________________________________________________________________
sample 24 ms submission
def sumConsecutive(n: int):
    return n * (n + 1) // 2

class Solution:
    def distributeCandies(self, candies: int, numPeople: int) -> List[int]:
        fullGifts = math.floor((math.sqrt(1 + 8 * candies) - 1) / 2)
        fullDistributions = fullGifts // numPeople
        firstPerson = sumConsecutive(fullDistributions - 1) * numPeople + fullDistributions
        current = fullDistributions * numPeople + 1
        candies -= sumConsecutive(current - 1)

        ans = [0] * numPeople
        
        for i in range(numPeople):
            ans[i] = firstPerson + i * fullDistributions
            if candies >= 0:
                toGive = min(candies, current)
                ans[i] += toGive
                candies -= toGive
                current += 1
        
        return ans
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def summation(self,n:int,a:int,r:int) ->int:
        return (n*(2*a + (n-1)*r))//2
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        if(num_people == 0):
            return []
        numberOfDis = math.floor((math.sqrt(2+8*candies) - 1) /2)
        numberOfExtra = numberOfDis % num_people
        numberOfDis = numberOfDis // num_people
        ans = []
        for i in range(1,num_people+1):
            if(i<= numberOfExtra):
                ans.append(self.summation(numberOfDis+1,i,num_people))
            else:
                ans.append(self.summation(numberOfDis,i,num_people))
        ans[numberOfExtra] += candies - sum(ans)        
        return ans
__________________________________________________________________________________________________
sample 32 ms submission
from math import sqrt
class Solution:
    def distributeCandies(self, candies: int, np: int) -> List[int]:
        s,n=[0]*np,int(sqrt(2*candies+1/4)-0.5)
        r,c=n//np,n%np
        if c:
            s[0]=(2+np*r)*(r+1)//2
            for i in range(1,c): s[i]=s[i-1]+r+1
            s[c]=(2*c+2+np*(r-1))*r//2
            for i in range(c+1,np): s[i]=s[i-1]+r
            s[c]+=candies-n*(n+1)//2
        else:
            s[0]=(2+np*(r-1))*r//2
            for i in range(1,np): s[i]=s[i-1]+r
            s[0]+=candies-n*(n+1)//2
        return s