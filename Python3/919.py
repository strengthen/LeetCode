__________________________________________________________________________________________________
sample 56 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.root = root
        temp = []
        stack = [root]
        while stack:
            a = stack.pop(0)
            #print(a)
            if a:
                temp.append(a)
                stack.append(a.left)
                stack.append(a.right)
                #print(temp)
        self.temp = temp
        


    def insert(self, v: int) -> int:
        n = len(self.temp)
        #print(n)
        p = self.temp[(n-1)//2]
        
        if n % 2 == 0:
            p.right = TreeNode(v)
            self.temp.append(p.right)
        else:
            p.left = TreeNode(v)
            self.temp.append(p.left)
        return p.val
        
        

    def get_root(self) -> TreeNode:
        #print(type(self.root))
        return self.root

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
__________________________________________________________________________________________________
sample 13676 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.tree = [root]
        for n in self.tree:
            if n.left:
                self.tree.append(n.left)
            if n.right:
                self.tree.append(n.right)
        self.tree.insert(0, None)

    def insert(self, v: int) -> int:
        newNode = TreeNode(v)
        self.tree.append(newNode)
        parent = self.tree[(len(self.tree) - 1) // 2]
        if parent.left == None:
            parent.left = newNode
        else:
            parent.right = newNode
        return parent.val        


    def get_root(self) -> TreeNode:
        return self.tree[1]

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
__________________________________________________________________________________________________
