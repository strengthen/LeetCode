__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    static ListNode h;
    public TreeNode sortedListToBST(ListNode head) {
       if (head == null) return null;
        h = head;
        int len = getLength(h);
        return getList(0, len-1);
    }
    
    
    public int getLength(ListNode h) {
        int len = 0;
        ListNode p =h;
        while (p!= null) {
            p = p.next;
            len++;
        }
        return len;        
    }
    
    public TreeNode getList(int start, int end) {
        if (start > end) return null;
        int mid = (start + end)/2;
        TreeNode left = getList(start, mid-1);

        TreeNode root = new TreeNode(h.val);
        h = h.next;
        TreeNode right =  getList(mid+1,end);
        root.left = left;
        root.right = right;
        return root;
    }
}
__________________________________________________________________________________________________
sample 36944 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    //Date:019-02-20
    //Start: 13:09
    //End: 14:00. Runtime: 3 ms, faster than 11.54%; Memory Usage: 37.8 MB, less than 98.19%.
     public TreeNode sortedListToBST(ListNode head){
        if (head == null) {
            return null;
        }

        ListNode mid = findMiddle(head).get(1);
        TreeNode res = new TreeNode(mid.val);
        if (head.next == null) {
            return res;
        }
        helper2(res, head);
        return res;
    }
    
    public void insert(TreeNode node, int value) {
        if (node == null) {
            return;
        }

        //很重要,避免插入重复值
        if (value == node.val) {
            return;
        }

        int rootVal;
        while (true) {
            rootVal = node.val;
            if (value < rootVal) {
                if (node.left == null) {
                    node.left = new TreeNode(value);
                    break;
                } else {
                    node = node.left;
                }
            } else {
                if (node.right == null) {
                    node.right = new TreeNode(value);
                    break;
                } else {
                    node = node.right;
                }
            }
        }

    }

    public List<ListNode> findMiddle(ListNode node) {
        ListNode slow = node;
        ListNode preSlow = slow;
        ListNode fast = node;

        while (fast != null && fast.next != null) {
            preSlow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        List<ListNode> res = new ArrayList<ListNode>();
        res.add(preSlow);
        res.add(slow);
        return res;
    }

    public void helper2(TreeNode root, ListNode node) {
        if (node == null) {
            return;
        }
        ListNode mid = findMiddle(node).get(1);
        ListNode preMid = findMiddle(node).get(0);
        insert(root, mid.val);
        if (node.next == null) {
            return;
        }
        ListNode right = mid.next;
        preMid.next = null;
        ListNode left = node;
        helper2(root, left);
        helper2(root, right);
    }
}
__________________________________________________________________________________________________
