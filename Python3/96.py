__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def numTrees(self, n: int) -> int:
        nums = {}
        nums[0] = 1
        nums[1] = 1
        
        def search(n):
            if n in nums:
                return nums[n]
            else:
                sum = 0
                for i in range(1, n+1):
                    sum += search(i-1) * search(n-i)
                nums[n] = sum
            return sum
        return search(n)            
__________________________________________________________________________________________________
sample 12932 kb submission
# 96. Unique Binary Search Trees (Catalan Number)

# dp, bottom up
class Solution:
    def numTrees(self, n: int) -> int:
        G = [1,1]
        for i in range(2,n+1):
            G.append(sum(G[j]*G[i-1-j] for j in range(i)))
        return G[n]        
__________________________________________________________________________________________________
