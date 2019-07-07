__________________________________________________________________________________________________
class Solution {
    List<TreeNode> list = new ArrayList<>();
    
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> tod = new HashSet<>();
        for(int t : to_delete)tod.add(t);
        dfs(root, tod);
        if(!tod.contains(root.val)){
            list.add(root);
        }
        return list;
    }
    
    void dfs(TreeNode root, Set<Integer> tod)
    {
        if(root == null)return;
        dfs(root.left, tod);
        dfs(root.right, tod);
        if(tod.contains(root.val)){
            if(root.left != null && !tod.contains(root.left.val)){
                list.add(root.left);
                root.left = null;
            }
            if(root.right != null && !tod.contains(root.right.val)){
                list.add(root.right);
                root.right = null;
            }
        }else{
            if(root.left != null && tod.contains(root.left.val)){
                root.left = null;
            }
            if(root.right != null && tod.contains(root.right.val)){
                root.right = null;
            }
        }
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
