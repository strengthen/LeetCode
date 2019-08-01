__________________________________________________________________________________________________
sample 1 ms submission
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
    public List<List<String>> printTree(TreeNode root) {
        List<List<String>> res = new ArrayList<>();
        if(root==null)  return res;
        int height = depth(root);
        int row = height, col = (int) (Math.pow(2, height)-1);
        List<String> cur = new ArrayList<>();
        for(int j=0; j<col; j++)    cur.add("");
        for(int i=0; i<row; i++)    res.add(new ArrayList<>(cur));
        make(root, res, row, 0, 0, col-1);
        return res;
    }
    public int depth(TreeNode root) {
        if(root==null)  return 0;
        return Math.max(depth(root.left), depth(root.right)) + 1;
    }
    public void make(TreeNode root, List<List<String>> res, int row, int curRow, int i, int j) {
        if(curRow==row || root==null)    return;
        int mid = i+(j-i)/2;
        res.get(curRow).set(mid, Integer.toString(root.val));
        make(root.left, res, row, curRow+1, i, mid - 1);
        make(root.right, res, row, curRow+1, mid + 1, j);      
    }
}
__________________________________________________________________________________________________
sample 37264 kb submission
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
    public List<List<String>> printTree(TreeNode root) {
        int h = getHeight(root);
        int w = (int)Math.pow(2, h) -1;
        System.out.println(w);
        List<List<String>> res = new ArrayList<List<String>>();
        String[][] ans = new String[h][w];
        for(int i =0 ; i< h; i++)
        {
            for(int j =0;j<w;j++)
            {
                ans[i][j] = "";
            }
        }
        print(root, 0, 0, w, ans);
        for(int i =0 ; i< h; i++)
        {
            List<String> temp = new ArrayList<>();
            for(int j =0;j<w;j++)
            {
                temp.add(ans[i][j]);
            }
            res.add(temp);
        }
        return res;
    }
    public void print(TreeNode root, int level, int minWidth, int maxWidth, String[][] ans)
    {
        if (root == null )
            return;
        ans[level][(minWidth+maxWidth)/2] = ""+root.val;
        print(root.left, level+1, minWidth, (minWidth+maxWidth)/2 , ans);
        print(root.right, level+1, ((minWidth+maxWidth)/2) +1, maxWidth, ans);
    }
    public int getHeight(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }
}
__________________________________________________________________________________________________
