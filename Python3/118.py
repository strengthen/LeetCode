__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for i in range(1, numRows):
            res += [list(map(lambda x, y: x+y, res[-1] + [0], [0] + res[-1]))]
        return res[:numRows]
__________________________________________________________________________________________________
sample 12960 kb submission
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows < 3:
            output = []
            for i in range(1,numRows+1):
                output.append(i*[1])
            return(output)
        cur = numRows*[1]
        prev = self.generate(numRows-1)
        for i in range(1,numRows-1):
            cur[i] = prev[-1][i-1]+prev[-1][i]
        prev.append(cur)
        return(prev)
__________________________________________________________________________________________________
