__________________________________________________________________________________________________
class UnionFind(object):
    def __init__(self, n):  # 初始化uf数组和组数目
        self.count = n
        self.uf = [i for i in range(n)]
        self.size = [1] * n # 每个联通分量的size

    def find(self, x):  # 判断节点所属于的组
        while x != self.uf[x]:
            self.uf[x] = self.uf[self.uf[x]]
            x = self.uf[x]
        return self.uf[x]

    def union(self, x, y):  # 连接两个节点
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root == y_root:
            return
        if self.size[x_root] < self.size[y_root]:
            x_root, y_root = y_root, x_root
        self.uf[y_root] = x_root
        self.size[x_root] += self.size[y_root]
        self.size[y_root] = 0
        self.count -= 1

    def connected(self, x, y):  # 判断两个节点是否联通
        return self.find(x) == self.find(y)

    def getCount(self):  # 返回所有组的数目
        return self.count
    
class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        row = len(A)
        col = len(A[0]) if row else 0
        uf = UnionFind(row * col)

        lookup = collections.defaultdict(list)
        vals = set()
        for i in range(row):
            for j in range(col):
                lookup[A[i][j]].append((i,j))
                vals.add(A[i][j])
                
        vals = sorted(list(vals))[::-1]
        res = vals[0]
        flags = set()
        for v in vals:
            for i, j in lookup[v]:
                flags.add((i,j))
                for x, y in [[0,1],[0,-1],[1,0],[-1,0]]:
                    m, n = i+x, j+y
                    if 0 <= m < row and 0 <= n < col:
                        if (m,n) in flags:
                            uf.union(i*col+j, m*col+n)
            if uf.connected(0, row*col-1):
                return v
        return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
