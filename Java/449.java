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
public class Codec {
    private TreeNode root=null;
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        this.root=root;
        return "";
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
__________________________________________________________________________________________________
sample 36992 kb submission
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "#";
        }
        
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        
        while (!qu.isEmpty()) {
            TreeNode cur = qu.poll();
            if (cur == null) {
                sb.append("#");
            } else {
                sb.append(cur.val);
                qu.offer(cur.left);
                qu.offer(cur.right);
            }
            sb.append(" ");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        data = data.trim();
        if (data.equals("#")) {
            return null;
        }
        
        String[] nodeVal = data.split("\\s+");
        Deque<TreeNode> qu = new ArrayDeque<>();
        TreeNode head = new TreeNode(Integer.parseInt(nodeVal[0]));
        qu.offer(head);
        int idx = 1;
        while (idx < nodeVal.length) {
            TreeNode cur = qu.poll();
            if (nodeVal[idx].equals("#")) {
                cur.left = null;
                idx++;
            } else {
                cur.left = new TreeNode(Integer.parseInt(nodeVal[idx++]));
                qu.offer(cur.left);
            }
            
            if (nodeVal[idx].equals("#")) {
                cur.right = null;
                idx++;
            } else {
                cur.right = new TreeNode(Integer.parseInt(nodeVal[idx++]));
                qu.offer(cur.right);
            }
        }
        return head;
    }
}
__________________________________________________________________________________________________
