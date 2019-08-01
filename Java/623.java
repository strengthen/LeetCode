__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(d == 1 || d == 0){
            TreeNode newNode = new TreeNode(v);
            if(d ==1){
                newNode.left = root;
            }else{
                newNode.right = root;
            }
            return newNode;
        }
        if(root != null && d > 1){
            root.left = addOneRow(root.left, v, d>2? d-1 : 1);
            root.right = addOneRow(root.right, v, d>2? d-1 : 0);
        }
        return root;
    }
}
__________________________________________________________________________________________________
sample 36972 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
    Queue<TreeNode> node = new LinkedList<>();
    Queue<Integer> depthOfNode = new LinkedList<>();

    if (root != null) {
      node.add(root);
      depthOfNode.add(1);
    }

    while (!node.isEmpty()) {
      TreeNode treeNode = node.remove();
      int depth = depthOfNode.remove();
      if (treeNode != null) {
        if (d - 1 == 0) {
          TreeNode newTree = new TreeNode(v);
          newTree.left = treeNode;
          root = newTree;
        } else if (depth == d - 1) {
          TreeNode leftChild = treeNode.left;
          TreeNode rightChild = treeNode.right;
          treeNode.left = new TreeNode(v);
          treeNode.right = new TreeNode(v);
          treeNode.left.left = leftChild;
          treeNode.right.right = rightChild;
        } else {
          node.add(treeNode.left);
          node.add(treeNode.right);
          depthOfNode.add(depth + 1);
          depthOfNode.add(depth + 1);
        }
      }
    }
    return root;
  }
}
__________________________________________________________________________________________________
