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

/*
This Solution is hack that works only because I changed the definition of TreeNode to have a setter method.
In order to avoid using a setter method : I would have to convert the inorder order of bst into the actual bst.
Not sure how to yet.
Why is the soln so slow?
*/


public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int x) { val = x; }
}

/*
* tree : 1, -1,4, 2,0,3,9
* 9->9+0
4->4+9
3->3+4+9
1-> 1+3+4+9
0->0+1+3+4+9
-1=-1+0+1+3+4+9 and so on.. every value is itself+lastSum
same concept as storing the references in an array and doing cumulative sum
*/
class Solution {
    
    //last can also be represented by the node 
    
    public TreeNode lastSum = null;
     public TreeNode convertBST(TreeNode root) {
         if(root==null) return null;
         convertBST(root.right);
         if(lastSum!=null){
             root.val+=lastSum.val;
        }
         lastSum=root;
         convertBST(root.left);   
         return root;
     }
}
__________________________________________________________________________________________________
sample 38328 kb submission
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
      private int sum=0;
    public TreeNode convertBST(TreeNode root) {
    if(root!=null){
        convertBST(root.right);
        sum+=root.val;
        root.val=sum;
        convertBST(root.left);
        }
        return root;        
    }
}
__________________________________________________________________________________________________
