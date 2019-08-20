__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        if sum(machines)%n !=0 :
            return -1
        goal = sum(machines)//n
        
        
        runningBalance = 0
        maxRB = 0
        for number in machines:
            runningBalance += number - goal
            if abs(runningBalance) > maxRB:
                maxRB = abs(runningBalance)
        return max(max(machines) - goal, maxRB)
__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        total, n = sum(machines), len(machines)
        if total % n != 0: return -1 # will never work
        target, res, toRight = total//n, 0, 0
        for machine in machines:
            toRight += machine - target
            res = max(res, abs(toRight), machine-target)
        return res
__________________________________________________________________________________________________
