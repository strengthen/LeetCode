__________________________________________________________________________________________________
sample 0 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root==null)
            return null;
        
        Node ls=root;
        Node prev,curr;
        while(ls!=null){
            curr=ls;
            prev=null;
            ls=null;
            while(curr!=null){
                if(curr.left!=null){
                    if(prev==null)
                        ls=curr.left;
                    else
                        prev.next=curr.left;
                    prev=curr.left;
                }
                if(curr.right!=null){
                    if(prev==null)
                        ls=curr.right;
                    else
                        prev.next=curr.right;
                    prev=curr.right;
                }
                curr=curr.next;
            }
        }
        return root;
    }
}
__________________________________________________________________________________________________
sample 36448 kb submission
/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
 
public class Solution {

    public void connect(TreeLinkNode root) {
    TreeLinkNode head = null; //head of the next level
    TreeLinkNode prev = null; //the leading node on the next level
    TreeLinkNode cur = root;  //current node of current level
        while(cur!=null){
            while(cur!=null){
                if(cur.left!=null){
                    if(prev==null){
                        prev = cur.left;
                        head = prev;
                    }
                    else{
                        prev.next = cur.left;
                        prev = prev.next;
                    }
                        
                }
                if(cur.right!=null){
                    if(prev==null){
                        prev = cur.right;
                        head = prev;
                    }
                    else{
                        prev.next = cur.right;
                        prev = prev.next;
                    }
                }
                cur = cur.next;
            }
            cur = head;
            head = null;
            prev = null;
        }
    }        
}
__________________________________________________________________________________________________
