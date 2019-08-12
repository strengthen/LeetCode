__________________________________________________________________________________________________
sample 112 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def __init__(self):
		self.values = []
		
	def sortedListToBST(self, head: ListNode) -> TreeNode:
		if head is None:
			return None
		temp = head
		while temp is not None:
			self.values.append(temp.val)
			temp = temp.next
		n = len(self.values)
		
		def buildTree(x, y, m):
			if x == y:
				return TreeNode(self.values[x])
			if x+1 == y:
				ans1 = TreeNode(self.values[y])
				ans2 = TreeNode(self.values[x])
				ans1.left = ans2
				return ans1
			if x+2 == y:
				ans = TreeNode(self.values[m])
				ans1 = TreeNode(self.values[x])
				ans2 = TreeNode(self.values[y])
				ans.left, ans.right = ans1, ans2
				return ans
			ans = TreeNode(self.values[m])
			ans.left = buildTree(x, m-1, (x+m-1)//2)
			ans.right = buildTree(m+1, y, (m+1+y)//2)
			return ans
		res = buildTree(0, n-1, n//2)
		return res        
__________________________________________________________________________________________________
sample 16896 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    @staticmethod
    def findMid(head):
        chop = None
        slow = head
        fast = head
        while(fast is not None and fast.next is not None):
            chop = slow
            slow = slow.next
            fast = fast.next.next
        chop.next = None
        return slow
    
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if (head is None):
            return None
        if (head.next is None):
            return TreeNode(head.val)
        mid = self.findMid(head)
        root = TreeNode(mid.val)
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(mid.next)
        return root
__________________________________________________________________________________________________
