__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        
        def insertNode(node,valarr):
            if node:
                if len(valarr)!=0:
                    if node.val<valarr[0]: 
                        newnode=TreeNode(valarr[0])
                        newnode.left=node
                        valarr=[]
                        return newnode,valarr
                    else:
                        node.left,_=insertNode(node.left,[])
                        node.right,valarr=insertNode(node.right,valarr)
                        return node,valarr
                else:
                    node.left,_=insertNode(node.left,[])
                    node.right,valarr=insertNode(node.right,valarr)
                    return node,valarr
            elif len(valarr)!=0 :
                newnode=TreeNode(valarr[0])
                valarr=[]
                return newnode,valarr
            else:
                return None,valarr
        root,vals=insertNode(root,[val])
        return root
__________________________________________________________________________________________________
sample 13072 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        if val > root.val:
            node = TreeNode(val)
            node.left = root

            return node
        else:
            self.helper(root,val)

            return root

    def helper(self, root, val):
        if root.right is None:
            node = TreeNode(val)
            root.right=node
        elif val > root.right.val:
            node = TreeNode(val)
            node.left = root.right
            root.right = node
        else:
            self.helper(root.right, val)
__________________________________________________________________________________________________
