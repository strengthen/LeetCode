__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        myDst = abs(target[0]) +  abs(target[1])
        closestGhost = float("inf")
        for ghost in ghosts:
            dist =  abs(target[0]-ghost[0]) + abs(target[1]-ghost[1] ) 
            if dist < closestGhost:
                closestGhost = dist
    
        if closestGhost <= myDst:
            return False
        else:
            return True
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        distanceToTarget = abs(target[0]) + abs(target[1])
        for ghostPos in ghosts:
            ghostDistance = abs(ghostPos[0] - target[0]) + abs(ghostPos[1] - target[1])
            if ghostDistance <= distanceToTarget:
                return False
        return True
__________________________________________________________________________________________________
