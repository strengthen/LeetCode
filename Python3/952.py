__________________________________________________________________________________________________
sample 684 ms submission
import collections
import math


def get_factors(n):
    factors = list(range(n + 1))
    for i in range(2, math.ceil(math.sqrt(n))):
        if factors[i] != i:
            continue
        for j in range(2 * i, n + 1, i):
            factors[j] = i
    return factors


FACTORS = get_factors(100000)


class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        parents = {}
        ranks = {}

        def ensure_node(x):
            if x not in parents:
                parents[x] = x
                ranks[x] = 0
                
        def find_root(x):
            while parents[x] != x:
                parents[x] = parents[parents[x]]
                x = parents[x]
            return x

        def merge(x, y):
            x = find_root(x)
            y = find_root(y)
            if x == y:
                return
            if ranks[x] < ranks[y]:
                x, y = y, x
            parents[y] = x
            if ranks[x] == ranks[y]:
                ranks[x] += 1
                
        for x in A:
            ensure_node(x)
            y = x
            while y != 1:
                z = FACTORS[y]
                ensure_node(z)
                merge(z, x)
                while True:
                    q, r = divmod(y, z)
                    if r != 0:
                        break
                    y = q
                    
        return max(collections.Counter(map(find_root, A)).values())
__________________________________________________________________________________________________
sample 1108 ms submission
from collections import defaultdict

# to factorize k numbers below N, if k is almost as big as N,
# it is more efficient to factorize all numbers by sieving
# to save space, only keep an array of the smallest factor for each number
def factorList(n):
    lst=[0]*(n+1)
    lst[1]=1
    for i in range(2,n+1):
        if lst[i]==0:
            for j in range(i,n+1,i):
                lst[j]=i
    return lst
    

def factors(faclist,n):
    while n>1:
        curr=faclist[n]
        yield curr
        n//=curr
    
# union find from https://medium.com/100-days-of-algorithms/day-41-union-find-d0027148376d
# with path compression
def find(data, i):
    if i != data[i]:
        data[i] = find(data, data[i])
    return data[i]

def union(data, i, j):
    pi, pj = find(data, i), find(data, j)
    if pi != pj:
        data[pi] = pj
    

class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        faclist=factorList(max(A))
        # for each prime number save a
        # representative, so that we have
        # a candidate to "union" on
        repre={}
        data={x:x for x in A}
        for n in A:
            for fac in factors(faclist,n):
                if fac in repre:
                    union(data,n,repre[fac])
                else:
                    repre[fac]=n
        counter=defaultdict(lambda :0)
        for n in A:
            counter[find(data,n)]+=1
        return max(counter.values())
__________________________________________________________________________________________________
