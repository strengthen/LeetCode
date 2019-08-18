__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
'''
class Solution:
    
    def has_sum(self, sum_, path):  # [10, 5, 2, 1] = [18, 8, 3, 1]
        tmp_path = [0] * len(path)
        count = 0
        for i in range(len(path)-1, -1, -1):
            if i< len(path)-1:
                tmp_path[i] += path[i]+tmp_path[i+1]
            else:
                tmp_path[i] = path[i]
            if tmp_path[i] ==sum_:
                count +=1
        return count        
    
    def helper(self, node, sum_, path):
        if node is None:
            return 
        
        path.append(node.val)
        self.result += self.has_sum(sum_, path)
        self.helper(node.left, sum_, path)
        self.helper(node.right, sum_, path)
        path.pop()
        return
                
    
    def pathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        
        path=[]
        self.result = 0;
        self.helper(root, sum_, path)
        return self.result
    
'''    
    
'''    
class Solution:    

    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        result = 0
        prefix_sum = 0
        hash_map ={}   # set up a dictionary, and initialize with a key-value pair of 0, 1
        hash_map[0]=1
        
        for i in range(len(nums)):
            prefix_sum += nums[i]
            if prefix_sum-k in hash_map:
                result += hash_map[prefix_sum -k]
            hash_map[prefix_sum]=1 if prefix_sum not in hash_map else hash_map[prefix_sum]+1  # one line
        return result 
    
    
    def helper(self, node, sum_, path):
        if node is None:
            return 
        
        path.append(node.val)
        if self.subarraySum(path,sum_)>0:
            print(path)
        self.result += self.subarraySum(path, sum_)
        self.helper(node.left, sum_, path)
        self.helper(node.right, sum_, path)
        path.pop()
        
        return
                
    
    def pathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        path=[]
        self.result = 0;
        self.helper(root, sum_, path)
        return self.result
    
    # does not really work 
   # [10, 5, 3]
#[10, 5, 3, 3]
#[10, 5, 3, -2]
#[10, 5, 2, 1]
#[10, -3, 11]
# [-, 5, 3, -] is counted three times.

'''

class Solution1:
    
    
    def helper(self, node, cur, sum_, lookup):
        if node is None:
            #print('None is reached')
            return 
        cur +=node.val;
        if cur - sum_ in lookup:
            self.result += lookup[cur - sum_]
        if cur in lookup:
            lookup[cur]+=1
        else:
            lookup[cur]=1
        #print('Before helpers, ', lookup)    
        #print('Call left')
        self.helper(node.left, cur,sum_, lookup)
        #print('Call right')
        self.helper(node.right, cur, sum_, lookup)
        #lookup[cur]-=1;   # This step is very curcial. Not fully un
        #print('After helpers,', lookup)
        #if lookup[cur]==0:
         #   del lookup[cur]
        #print('After Del,', lookup)    
        return
                
    
    def pathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        
        lookup={}
        lookup[0]=1
        self.result = 0;
        self.helper(root, 0, sum_, lookup)
        return self.result


class Solution:
    
    def pathSum(self, root, sum_):
        lookup = defaultdict(int)
        lookup[0] = 1
        self.ans = 0
        self.helper(root, 0, sum_, lookup)
        return self.ans
    
    
    def helper(self, node, pre_sum, sum_, lookup):
        
        if not node:
            return
        pre_sum += node.val
        if pre_sum - sum_ in lookup:
            self.ans += lookup[pre_sum - sum_]
        lookup [pre_sum] += 1
        self.helper(node.left, pre_sum, sum_, lookup)
        self.helper(node.right, pre_sum, sum_, lookup)
        lookup[pre_sum] -= 1
        return 
__________________________________________________________________________________________________
sample 13364 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, goal: int) -> int:
        if root is None:
            return 0
        stack=[(root,[root.val])]
        num=0
        while stack:
            node,values=stack.pop()
            num+=values.count(goal)
            if node.left:
                stack.append((node.left,[val+node.left.val for val in values]+[node.left.val]))
            if node.right:
                stack.append((node.right,[val+node.right.val for val in values]+[node.right.val]))
        return num
__________________________________________________________________________________________________
