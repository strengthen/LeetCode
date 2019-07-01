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
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        uf = UnionFind(N)
        logs.sort(key = lambda x: x[0])
        for log, a, b in logs:
            uf.union(a, b)
            if uf.count == 1:
                return log
        return -1
__________________________________________________________________________________________________

__________________________________________________________________________________________________
