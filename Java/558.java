__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 41.6 MB
class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        if(quadTree1 == null || quadTree2 == null) return null;
        
        if(quadTree1.isLeaf && quadTree2.isLeaf) {
            return new Node(quadTree1.val || quadTree2.val, true, null, null, null, null);
        } else if(quadTree1.isLeaf) {
            return quadTree1.val ? quadTree1 : quadTree2;
        } else if(quadTree2.isLeaf) {
            return quadTree2.val ? quadTree2 : quadTree1;
        } else {
            Node nTL = intersect(quadTree1.topLeft, quadTree2.topLeft);
            Node nTR = intersect(quadTree1.topRight, quadTree2.topRight);
            Node nBL = intersect(quadTree1.bottomLeft, quadTree2.bottomLeft);
            Node nBR = intersect(quadTree1.bottomRight, quadTree2.bottomRight);
            
            if(nTL.isLeaf && nTR.isLeaf && nBL.isLeaf && nBR.isLeaf) {
                if(nTL.val == nTR.val && nTR.val == nBL.val && nBL.val == nBR.val) {
                    return new Node(nTL.val, true, null, null, null, null);
                }
            }
            return new Node(false, false, nTL, nTR, nBL, nBR);
        }
    }
}
__________________________________________________________________________________________________
sample 42508 kb submission
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        if (quadTree1.isLeaf) {
            if (quadTree1.val) {
                return quadTree1;
            } else {
                return quadTree2;
            }
        } 
        if (quadTree2.isLeaf) {
            if (quadTree2.isLeaf) {
                if (quadTree2.val) {
                    return quadTree2;
                } else {
                    return quadTree1;
                }
            }
        }
        
        Node topLeft = intersect(quadTree1.topLeft, quadTree2.topLeft);
        Node topRight = intersect(quadTree1.topRight, quadTree2.topRight);
        Node bottomLeft = intersect(quadTree1.bottomLeft, quadTree2.bottomLeft);
        Node bottomRight = intersect(quadTree1.bottomRight, quadTree2.bottomRight);
        
        if (topLeft.val == topRight.val && topRight.val == bottomLeft.val && bottomLeft.val == bottomRight.val && 
           topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf) {
            return new Node(topLeft.val, true, null, null);
            
        } else {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
}
__________________________________________________________________________________________________
