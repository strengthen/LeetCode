__________________________________________________________________________________________________
sample 1 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> ans = new ArrayList<>();
        helper(ans,root);
        return ans;
    }
    
    private void helper(List<Integer> ans, Node node) {
        if(node == null) {
            return;
        }
        ans.add(node.val);
        for(Node n : node.children) {
            helper(ans,n);
        }
    }
}
__________________________________________________________________________________________________
sample 42344 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
         List<Integer> res = new ArrayList<>();
        helper(root,res);
        
        return res;
    }
    public void helper(Node root, List<Integer> res){
        if(root==null)
            return;
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            Node n = stack.pop();
            res.add(n.val);
            for(int i=n.children.size()-1;i>=0;i--){
                stack.push(n.children.get(i));
            }
        }
    }
    public void helper1(Node root, List<Integer> res){
        if(root==null)
            return;
        res.add(root.val);
        for(Node c:root.children){
            helper1(c,res);
        }
    }
}
__________________________________________________________________________________________________
