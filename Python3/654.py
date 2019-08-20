__________________________________________________________________________________________________
sample 164 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        stack = []
        for num in nums:
            node = TreeNode(num)
            
            # no dups so no need for <=
            while stack and stack[-1].val < num:
                # because anything in the stack must be on the left side
                node.left = stack.pop()
                
            # if anything left in stack,
            # it must be larger than num and current num is on the right by index
            if stack:
                stack[-1].right = node
                
            # put current node on the stack for next nums
            stack.append(node)

        # largest item must be the first thing in the stack otherwise it wouldve been popped
        return stack[0]
__________________________________________________________________________________________________
sample 13260 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        def max_bin_tree(nums):
            if len(nums) == 0:
                return
            else:
                max_index = 0
                for i in range(len(nums)):
                    if nums[i].val > nums[max_index].val:
                        max_index = i

                root = nums[max_index]
                root.left = max_bin_tree(nums[:max_index])
                root.right = max_bin_tree(nums[max_index+1:])

                return root
        
        for i in range(len(nums)):
            nums[i] = TreeNode(nums[i])
        root_node = max_bin_tree(nums)
        return root_node
__________________________________________________________________________________________________
