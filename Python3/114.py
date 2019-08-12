__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        st=[root];head1=TreeNode(0)
        if not root:
            return
        head=head1
        
        while st:
            
            x=st.pop()
            head.right=x
            if x.right:
                st.append(x.right)
            if x.left:
                st.append(x.left)
            x.left=None
            head=head.right
        head.right=None
__________________________________________________________________________________________________
sample 13220 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def get_nodes(root):
    if not root:
        return []
    
    left = get_nodes(root.left)
    right = get_nodes(root.right)
    
    return [root] + left + right 

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        ordered = get_nodes(root)
        for i, node in enumerate(ordered[:-1]):
            node.left = None
            node.right = ordered[i + 1]        
__________________________________________________________________________________________________
