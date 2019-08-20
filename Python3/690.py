__________________________________________________________________________________________________
sample 160 ms submission
"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        hmap = {emp.id:emp for emp in employees}
        lead = hmap[id]
                
        stack = [lead]
        res = 0
        while len(stack)>0:
            curr = stack.pop()
            res += curr.importance
            for sub in curr.subordinates:
                stack.append(hmap[sub])
                
        return res
__________________________________________________________________________________________________
sample 14072 kb submission
"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        ret = 0
        em = {}
        for e in employees:
            em[e.id] = e
        q = [id]
        while q:
            c = em[q.pop(-1)]
            ret += c.importance
            for s in c.subordinates:
                q.append(s)
        return ret
__________________________________________________________________________________________________
