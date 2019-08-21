__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        M = k**(n-1)
        P = [q*k+i for i in range(k) for q in range(M)]
        ans = []

        for i in range(k**n):
            j = i
            while P[j] >= 0:
                ans.append(str(j // M))
                P[j], j = -1, P[j]

        return "".join(ans) + "0" * (n-1)
__________________________________________________________________________________________________
sample 13388 kb submission
import itertools

class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        def dfs(node, ans):
            while d[node] != 0:
                d[node] -= 1
                dfs(node[1:] + str(d[node]), ans)
            ans.append(node[0])
        if n == 1:
            return ''.join(map(str, range(k)))
        d = {''.join(p): k for p in itertools.product(map(str, range(k)), repeat=n-1)}
        ans = ['0'] * (n-2)
        # dfs('0' * (n-1), ans)
        nodes = ['0' * (n-1)]
        while nodes:
            node = nodes[-1]
            if d[node] != 0:
                d[node] -= 1
                nodes.append(node[1:] + str(d[node]))
                continue
            ans.append(node[0])
            nodes.pop()
        return ''.join(ans)
__________________________________________________________________________________________________
