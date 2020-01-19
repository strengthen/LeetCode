__________________________________________________________________________________________________
sample 464 ms submission
class Solution:
    def makeConnected(self, n: int, con: List[List[int]]) -> int:
        p = [i for i in range(n)]
        cnt = n
        spare = 0
        def find(x):
            while x != p[x]:
                p[x] = p[p[x]]
                x = p[x]
            
            return x
 
        for x,y in con:            
            p1 = find(x)
            p2 = find(y)
            
            if p1 != p2:
                p[p1] = p2
                cnt -= 1
            else:
                spare += 1
        
            # print(x, y, p1, p2, cnt, spare)
        
        if cnt == 1:
            return 0
        elif spare >= cnt-1:
            return cnt-1
        else:
            return -1
__________________________________________________________________________________________________
sample 480 ms submission
class DisjointSet:
        def __init__(self, idx):
            self.head = idx
            self.tail = idx
            self.length = 1


class ListNode:
    def __init__(self, idx):
        self.val = idx
        self.next = None
        self.set = None


class Solution:
    # Method 1: disjoint set linked-list implementation
    def makeConnected(self, n, connections):
        nodeList = []  # node list should be in the same order of occurrence with node indices
        Unions = [] # a list of all unions

        def make_set(x):
            # # tell if x already in some other sets
            # if x in visited:
            #     return
            Sx = DisjointSet(x)
            Unions.append(Sx)
            return Sx


        def find_set(x):
            return nodeList[x].set.head
        

        def union(x, y):
            if find_set(x) == find_set(y): return
            Sx = nodeList[x].set
            Sy = nodeList[y].set

            # always keep the longer linked-list and append the shorter linked-list
            if Sx.length < Sy.length: Sx, Sy = Sy, Sx

            # append Sy at the end of Sx
            nodeList[Sx.tail].next = nodeList[Sy.head]
            Sx.tail = Sy.tail

            # modify the set pointer of elements in Sy
            pointer = nodeList[Sy.head]
            while pointer:
                pointer.set = Sx
                pointer = pointer.next

            Sx.length += Sy.length
            Unions.remove(Sy)
            del Sy

        for i in range(n):
            node = ListNode(i)
            nodeList.append(node)
            node.set = make_set(i)

        # init
        redunConnNum = 0
        for v1, v2 in connections:
            # print([v1, v2])
            if find_set(v1) == find_set(v2):
                redunConnNum += 1
            else:
                union(v1, v2)
        
        print(redunConnNum, len(Unions) - 1)
        return -1 if redunConnNum < len(Unions) - 1 else len(Unions) - 1
    
    
    
    # Method 2: disjoint set rooted-tree implementation  
    # time = 5%, space = 100%
    def makeConnected(self, n, connections):
        
        def union(x, y):
            if DisjointSetRepres[x] == DisjointSetRepres[y]: return
            
            tempRepres = DisjointSetRepres[y]
            for vertex in DisjointSets[tempRepres]:
                DisjointSetRepres[vertex] = DisjointSetRepres[x]
            DisjointSets[DisjointSetRepres[x]] += DisjointSets[tempRepres]
            
            DisjointSets.pop(tempRepres, None)
        
        # init var
        DisjointSetRepres = dict()
        DisjointSets = dict()
        redunConnNum = 0
        
        # init (make_set function)
        for i in range(n):
            DisjointSetRepres[i] = i
            DisjointSets[i] = [i]

        for v1, v2 in connections:
            # (find_set function)
            if DisjointSetRepres[v1] == DisjointSetRepres[v2]:
                redunConnNum += 1
            else:
                union(v1, v2)

        return -1 if redunConnNum < len(DisjointSets) - 1 else len(DisjointSets) - 1
    
    # disjoint set simplified version of rooted-tree implementation
    # time = 99%, space = 100%
    def makeConnected(self, n, connections):
        r = [i for i in range(n)] # let r denote the representative of the set which contains this element
        unionNum = n
        redunConnNum = 0
        def find(x):
            while x != r[x]:
                r[x] = r[r[x]] # path compression operation is done here
                x = r[x]
            
            return x
 
        for x, y in connections:
            r1 = find(x) # find representative of x
            r2 = find(y) # find representative of y
            
            if r1 != r2:
                r[r1] = r2      # union: set representative of r1 as r2
                unionNum -= 1   # every union operation would reduce union number by 1
            else:
                redunConnNum += 1
        
        return -1 if redunConnNum < unionNum - 1 else unionNum - 1
__________________________________________________________________________________________________
