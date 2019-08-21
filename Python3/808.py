__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def soupServings(self, N: int) -> float:
        if N>4800:
            return 1.0
        soups=[[100,0],[75,25],[50,50],[25,75]]
        memo=collections.defaultdict(float)
        def dfs(A,B):
            if (A,B) in memo:
                return memo[(A,B)]
            if A<=0:
                if B<=0:
                    return 0.5
                return 1.0
            if B<=0:
                return 0.0
            res=0.0
            for soup in soups:
                res+=dfs(A-soup[0], B-soup[1])
            res/=len(soups)
            memo[(A,B)]=res
            return res
        return dfs(N, N)
__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def soupServings(self, N: int) -> float:
        if N >= 4000:
            return 1
        
        self.ans, self.dp = 0, {}
        self.operations = [(100, 0), (75, 25), (50, 50), (25, 75)]
        return self.__soupServings(N, N)

    def __soupServings(self, A, B):
        if A <= 0 and B <= 0:
            return 0.5
        if A <= 0:
            return 1.0
        if B <= 0:
            return 0.0

        if (A, B) not in self.dp:
            self.dp[(A, B)] = 0.25 * sum([
                self.__soupServings(A - self.operations[op][0],
                                    B - self.operations[op][1])
                for op in range(4)
            ])

        return self.dp[(A, B)]
__________________________________________________________________________________________________
