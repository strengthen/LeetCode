__________________________________________________________________________________________________
sample 228 ms submission
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        if quadTree1.isLeaf:
            if quadTree1.val:
                return quadTree1
            else:
                return quadTree2
        elif quadTree2.isLeaf:
            if quadTree2.val:
                return quadTree2
            else:
                return quadTree1
        else:            
            tl =        self.intersect(quadTree1.topLeft,quadTree2.topLeft)
            tr =        self.intersect(quadTree1.topRight,quadTree2.topRight)
            bl =        self.intersect(quadTree1.bottomLeft,quadTree2.bottomLeft)
            br =        self.intersect(quadTree1.bottomRight,quadTree2.bottomRight)
            
            if tl.isLeaf and tr.isLeaf and bl.isLeaf and br.isLeaf and tl.val==tr.val and tr.val==bl.val and bl.val==br.val:
                return Node(tl.val,True,None,None,None,None)
            else:
                return Node(None,False,tl,tr,bl,br)
__________________________________________________________________________________________________
sample 232 ms submission
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        if quadTree1 is None or quadTree2 is None:
            return None

        if quadTree1.isLeaf:
            return quadTree1 if quadTree1.val else quadTree2
        if quadTree2.isLeaf:
            return quadTree2 if quadTree2.val else quadTree1
            
        quadTree1.topLeft = self.intersect(quadTree1.topLeft,
                                           quadTree2.topLeft)
        quadTree1.topRight = self.intersect(quadTree1.topRight,
                                            quadTree2.topRight)
        quadTree1.bottomLeft = self.intersect(quadTree1.bottomLeft,
                                              quadTree2.bottomLeft)
        quadTree1.bottomRight = self.intersect(quadTree1.bottomRight,
                                               quadTree2.bottomRight)
        if quadTree1.topLeft.isLeaf \
           and quadTree1.topRight.isLeaf \
           and quadTree1.bottomLeft.isLeaf \
           and quadTree1.bottomRight.isLeaf \
           and (quadTree1.topLeft.val \
                == quadTree1.topRight.val \
                == quadTree1.bottomLeft.val \
                == quadTree1.bottomRight.val):
            quadTree1 = Node(quadTree1.topLeft.val, True, None, None, None,
                             None)
        else:
            quadTree1.val = False

        return quadTree1        
__________________________________________________________________________________________________
