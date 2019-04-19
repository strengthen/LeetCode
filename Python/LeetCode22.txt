__________________________________________________________________________________________________
36ms
class Solution:
    def generateParenthesis(self, n: 'int') -> 'List[str]':
        if n == 0: return ['']
        ans = []
        def backtrack(S = '',left = 0, right = 0):
            if len(S) == 2 * n:
                ans.append(S)
                return
            if left < n:
                backtrack(S+'(',left + 1, right)
            if right < left:
                backtrack(S+')',left,right + 1)
        
        backtrack()
        return ans
__________________________________________________________________________________________________
40ms
class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        
        def helper(l_num = 0, r_num = 0, s = ''):
            if len(s) == 2*n:
                res.append(s)
                return
            
            if l_num < n:
                helper(l_num+1,r_num,s+'(')
            if l_num > r_num:
                helper(l_num,r_num+1,s+')')
        helper()
        return res
__________________________________________________________________________________________________
44ms
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        if n == 0:
            return [""]

        def gene_par(index, present_sum, strs):
            if index == 2*n:
                if present_sum == 1:
                    result.append(strs+")")
                return

            if present_sum > 0:
                gene_par(index + 1, present_sum+1, strs+"(")
                gene_par(index + 1, present_sum-1, strs + ")")
            else:
                gene_par(index + 1, present_sum + 1, strs + "(")

        gene_par(1, 0, "")
        return result
__________________________________________________________________________________________________
12396 kb 
class Solution:
    def generateParenthesis(self, n: 'int') -> 'List[str]':
        if n <= 0:
            return []
        
        if n == 1:
            return ["()"]
        else:
            prev = self.generateParenthesis(n-1)
            fresh = set()
            for line in prev:
                fresh.add("()" + line)
                fresh.add(line + "()")
                fresh.add("(" + line + ")")
                for i in range(1,len(line)):
                    fresh.add(line[:i] + "()" + line[i:])
            return list(fresh)
__________________________________________________________________________________________________
12424 kb
class Solution:
    def generateParenthesis(self, n: 'int') -> 'List[str]':
        
        res=[]
    
        def rec(str,  iter):
            if iter == 0 :
                #print(str)
                if str not in res:
                    res.append(str)
                return
            rec(str+'()', iter-1)
            rec('()'+str, iter-1)
            rec('('+str+')', iter-1)
        
        #rec('', n)
        #return res
        def BT(str, left, right):
            #print(str,left,right)
            if(left<0):
                return
            if(right<0):
                return
            if(left>right ):
                return
            
            if(left==0 and right==0):
                print(str)
                res.append(str)
                return
            BT(str+'(', left-1, right)
            BT(str+')', left, right-1)
        BT('', n,n)
        return res
__________________________________________________________________________________________________
