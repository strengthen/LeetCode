__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ret = []
        remove(s, ret, 0, 0, '()')
        return ret 

def remove(s, ret, last_i, last_j, par):
    stack = 0
    for i in range(last_i, len(s)):
        if s[i] == par[0]:
            stack += 1
        elif s[i] == par[1]:
            stack -= 1
        if stack >= 0:
            continue 
        # more ) 
        for j in range(last_j, i+1):
            if s[j] == par[1] and (j == last_j or s[j-1] != par[1]):
                remove(s[:j]+s[j+1:], ret, i, j, par)
        return 

    rev_s = s[::-1]
    if par[0] == '(':
        remove(rev_s, ret, 0, 0, ')(')
    else:
        ret.append(rev_s)
__________________________________________________________________________________________________
sample 12988 kb submission
class Solution(object):

    def __init__(self):
        self.valid_expressions = None
        self.min_removed = None

    def reset(self):
        self.valid_expressions = set()
        self.min_removed = float("inf")

    def remaining(self, string, index, left_count, right_count, expr, rem_count):
        if index == len(string):
            if left_count == right_count:
                if rem_count <= self.min_removed:
                    possible_ans = "".join(expr)
                    if rem_count < self.min_removed:
                        self.valid_expressions = set()
                        self.min_removed = rem_count
                    self.valid_expressions.add(possible_ans)    
        else:        
            current_char = string[index]
            if current_char != '(' and  current_char != ')':
                expr.append(current_char)
                self.remaining(string, index + 1, left_count, right_count, expr, rem_count)
                expr.pop()
            else:
                self.remaining(string, index + 1, left_count, right_count, expr, rem_count + 1)
                expr.append(current_char)
                if string[index] == '(':
                    self.remaining(string, index + 1, left_count + 1, right_count, expr, rem_count)
                elif right_count < left_count:
                    self.remaining(string, index + 1, left_count, right_count + 1, expr, rem_count)
                expr.pop()

    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        self.reset()
        self.remaining(s, 0, 0, 0, [], 0)
        return list(self.valid_expressions)
__________________________________________________________________________________________________
