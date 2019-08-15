__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def __init__(self):
        self.memo = {}
    
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input in self.memo:
            return self.memo[input]
        
        res = []
        for i in range(len(input)):
            if input[i] in '+-*':
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
            
                for l in left:
                    for r in right:
                        if input[i] == '+':
                            res.append(l+r)
                        elif input[i] == '-':
                            res.append(l-r)
                        else:
                            res.append(l*r)
                            
        if len(res)==0:
            res.append(int(input))
            
        self.memo[input] = res
        return res        
__________________________________________________________________________________________________
sample 13128 kb submission
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input.isdigit():
            return [int(input)]
        return self.allPossibleValues(input)
    
    def allPossibleValues(self, input):
        if input.isdigit():
            return [int(input)]
        res = []
        for i in range(len(input)):
            if input[i] in ('+', '-', '*'):
                leftPossibleValues = self.allPossibleValues(input[:i])
                rightPossibleValues = self.allPossibleValues(input[i + 1:])
                for l_each in leftPossibleValues:
                    for r_each in rightPossibleValues:
                        res.append(eval(str(l_each)+ input[i] + str(r_each)))
        return res        
__________________________________________________________________________________________________
