__________________________________________________________________________________________________
class Node:
    def __init__(self, start, end, x):
        self.start = start
        self.end = end
        self.counter = collections.Counter([x])
        self.left = None
        self.right = None

def merge_counter(c1, c2):
    c = collections.Counter()
    for k in c1:
        c[k] = c.get(k, 0) + c1[k]
    for k in c2:
        c[k] = c.get(k, 0) + c2[k]
    return c
    
class MajorityChecker:
    def __init__(self, arr: List[int]):
        def createTree(arr, l, r):
            if l > r:
                return None
            if l == r:
                return Node(l, r, arr[l])
            root = Node(l, r, 0)
            mid = (l + r) // 2
            root.left = createTree(arr, l, mid)
            root.right = createTree(arr, mid + 1, r)
            root.counter = merge_counter(root.left.counter, root.right.counter)
            return root
        
        self.root = createTree(arr, 0, len(arr) - 1)

    def query(self, left: int, right: int, threshold: int) -> int:
        def counter(root, i, j):
            if root.start == i and root.end == j:
                return root.counter
            mid = (root.start + root.end) // 2
            if j <= mid:
                return counter(root.left, i, j)
            elif i >= mid + 1:
                return counter(root.right, i, j)
            else:
                l_counter = counter(root.left, i, mid)
                r_counter = counter(root.right, mid + 1, j)
                return merge_counter(l_counter, r_counter)
        
        count = counter(self.root, left, right)
        x, x_freq = count.most_common(1)[0]
        if x_freq >= threshold:
            return x
        else:
            return -1
__________________________________________________________________________________________________

__________________________________________________________________________________________________
