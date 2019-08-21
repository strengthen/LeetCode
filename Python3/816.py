__________________________________________________________________________________________________
sample 44 ms submission
class Solution(object):
    def ambiguousCoordinates(self, s):
        '''
        For each place to put the comma, we separate the string into two fragments. For example, with a string like "1234", we could separate it into fragments "1" and "234", "12" and "34", or "123" and "4".
Then, for each fragment, we have a choice of where to put the period, to create a list make(...) of choices. For example, "123" could be made into "1.23", "12.3", or "123".
Because of extranneous zeroes, we should ignore possibilities where the part of the fragment to the left of the decimal starts with "0" (unless it is exactly "0"), and ignore possibilities where the part of the fragment to the right of the decimal ends with "0", as these are not allowed.
Note that this process could result in an empty answer, such as for the case S = "(000)".
        '''
        '''
        Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
        '''
        '''def make(frag):
            N = len(frag)
            for d in range(1, N+1):
                left = frag[:d]
                right = frag[d:]
                if ((not left.startswith('0') or left == '0')
                        and (not right.endswith('0'))):
                    yield left + ('.' if d != N else '') + right
        S = S[1:-1]
        return ["({}, {})".format(*cand)
                for i in range(1, len(S))
                for cand in itertools.product(make(S[:i]), make(S[i:]))]'''
        def make(frag):
            fragLen = len(frag)
            for idx in range(1, fragLen+1):
                left = frag[:idx]
                right = frag[idx:]
                #if (left == '0' or not left.startswith('0')) and (not right.endswith('0')):
                if ((left == '0' or not left.startswith('0'))
                        and not right.endswith('0')):
                    yield left + ('.' if idx != fragLen else '') + right
        s = s[1:-1]
        return ['({}, {})'.format(*cand) for i in range(1, len(s)) for cand in itertools.product(make(s[:i]), make(s[i:]))]
        '''result = []
        s = s[1:-1]
        for i in range(1, len(s)):
            for x in self.get_coordinate(s[:i]):
                for y in self.get_coordinate(s[i:]):
                    result.append('({}, {})'.format(x, y))
        return list(map(str, result))
    def get_coordinate(self, x):
        if len(x) == 1:
            return x
        if x[0] == '0' and x.endswith('0'):
            return []
        if x[0] == '0':
            return [x[0] + '.' + x[1:]]
        if x.endswith('0'):
            return [x]
        return [x[:i] + '.' + x[i:] for i in range(1, len(x))] + [x]'''
        '''res = []
        s = s[1:-1]
        for i in range(1, len(s)):
            for x in self.getCoord(s[:i]):
                for y in self.getCoord(s[i:]):
                    res.append('({}, {})'.format(x,y))
        return res
    def getCoord(self,x):
        if len(x) == 1:
            return x 
        if x[0]=='0' and x.endswith('0'):
            return []
        if x[0] == '0':
            return [x[0]+'.'+x[1:]]
        if x.endswith('0'):
            return [x]
        return [x[:i]+'.'+x[i:] for i in range(1, len(x))]+[x]'''
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        '''
        if S == "": return []
        if S == "0": return [S]
        if S == "0XXX0": return []
        if S == "0XXX": return ["0.XXX"]
        if S == "XXX0": return [S]
        return [S, "X.XXX", "XX.XX", "XXX.X"...]
        '''
        S = S[1:-1]
        def f(S):
            if not S or len(S) > 1 and S[0] == S[-1] == '0': return []
            if S[-1] == '0': return [S]
            if S[0] == '0': return [S[0] + '.' + S[1:]]
            return [S] + [S[:i] + '.' + S[i:] for i in range(1, len(S))]
        return ['(%s, %s)' % (a, b) for i in range(len(S)) for a, b in itertools.product(f(S[:i]), f(S[i:]))]
__________________________________________________________________________________________________
