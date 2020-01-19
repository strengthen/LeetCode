__________________________________________________________________________________________________
sample 696 ms submission
class Solution(object):
	def reconstructMatrix(self, upper, lower, colsum):
		n = len(colsum)
		res = [colsum, [0] * n]
		c0 = colsum[0]
		res[0][0] = upper - (sum(colsum) - c0)
		res[1][0] = c0 - res[0][0]
		if res[1][0] == lower:
			return res
		return [] 
__________________________________________________________________________________________________
sample 708 ms submission
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if sum(colsum)!=upper+lower:
            return []
        up = [0]*len(colsum)
        low = [0]*len(colsum)
        for i in range(len(colsum)):
            if colsum[i]==2:
                up[i]=1
                low[i]=1
                upper -=1
                lower -= 1
        if upper<0 or lower<0:
            return []
        for i in range(len(colsum)):
            if colsum[i]==1:
                if upper == 0:
                    low[i]=1
                else:
                    up[i]=1
                    upper-=1
        return [up,low]
__________________________________________________________________________________________________
