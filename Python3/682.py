__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        history = []
        for op in ops:
            if op == 'C':
                history.pop()
            elif op == 'D':
                history.append(history[-1] * 2)
            elif op == '+':
                history.append(history[-1] + history[-2])
            else:
                history.append(int(op))
        return sum(history)
__________________________________________________________________________________________________
sample 12968 kb submission
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        l = []
        for op in ops:
            if op == "C":
                l.pop()
            elif op == "D":
                l.append(l[-1]  * 2)
            elif op == "+":
                l.append(l[-1] + l[-2])
            else:
                l.append(int(op))
        return sum(l)
__________________________________________________________________________________________________
